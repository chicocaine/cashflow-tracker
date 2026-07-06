-- ============================================================================
-- SQLite schema derived from the given C structs
-- ============================================================================
-- Notes on type mapping:
--   stdid_t   -> INTEGER PRIMARY KEY (SQLite rowid alias, auto-increments)
--   uuid_t    -> TEXT, stored as a 36-char canonical UUID string
--   time_t    -> INTEGER (unix epoch seconds)
--   char[N]   -> TEXT with a CHECK(length(...) <= N) guard
--   Enums     -> stored as INTEGER. Replace the placeholder CHECK ranges
--                below with the real enum bounds/values from your C headers.
--   int (bool)-> INTEGER CHECK(x IN (0,1))
-- ============================================================================

PRAGMA foreign_keys = ON;

-- ----------------------------------------------------------------------------
-- account
-- ----------------------------------------------------------------------------
CREATE TABLE account (
    id               INTEGER PRIMARY KEY AUTOINCREMENT,
    name             TEXT    NOT NULL CHECK (length(name) <= 64),
    note             TEXT             CHECK (note IS NULL OR length(note) <= 256),
    initial_balance  REAL    NOT NULL DEFAULT 0,
    current_balance  REAL    NOT NULL DEFAULT 0,
    archived         INTEGER NOT NULL DEFAULT 0 CHECK (archived  IN (0, 1)),
    suspended        INTEGER NOT NULL DEFAULT 0 CHECK (suspended IN (0, 1)),
    type             INTEGER NOT NULL, -- AccountType enum   (adjust CHECK to real values)
    currency         INTEGER NOT NULL, -- Currency enum      (adjust CHECK to real values)
    created_at       INTEGER NOT NULL DEFAULT (strftime('%s','now')),
    updated_at       INTEGER NOT NULL DEFAULT (strftime('%s','now'))
);

CREATE TRIGGER trg_account_updated_at
AFTER UPDATE ON account
FOR EACH ROW
BEGIN
    UPDATE account SET updated_at = strftime('%s','now') WHERE id = OLD.id;
END;

-- ----------------------------------------------------------------------------
-- transaction_category
-- ----------------------------------------------------------------------------
CREATE TABLE transaction_category (
    id           INTEGER PRIMARY KEY AUTOINCREMENT,
    name         TEXT    NOT NULL CHECK (length(name) <= 64),
    description  TEXT             CHECK (description IS NULL OR length(description) <= 128),
    created_at   INTEGER NOT NULL DEFAULT (strftime('%s','now')),
    updated_at   INTEGER NOT NULL DEFAULT (strftime('%s','now')),
    archived     INTEGER NOT NULL DEFAULT 0 CHECK (archived IN (0, 1))
);

CREATE TRIGGER trg_transaction_category_updated_at
AFTER UPDATE ON transaction_category
FOR EACH ROW
BEGIN
    UPDATE transaction_category SET updated_at = strftime('%s','now') WHERE id = OLD.id;
END;

-- ----------------------------------------------------------------------------
-- transaction
-- "transaction" is a reserved word in SQL, so it must be quoted everywhere.
-- ----------------------------------------------------------------------------
CREATE TABLE "transaction" (
    id               TEXT    PRIMARY KEY CHECK (length(id) = 36), -- uuid_t
    description      TEXT             CHECK (description IS NULL OR length(description) <= 128),
    note             TEXT             CHECK (note IS NULL OR length(note) <= 256),
    amount           REAL    NOT NULL,
    type             INTEGER NOT NULL, -- TransactionType enum (adjust CHECK to real values)
    category_id      INTEGER NOT NULL,
    currency         INTEGER NOT NULL, -- Currency enum        (adjust CHECK to real values)
    archived         INTEGER NOT NULL DEFAULT 0 CHECK (archived IN (0, 1)),
    from_account_id  INTEGER,          -- nullable
    to_account_id    INTEGER,          -- nullable
    created_at       INTEGER NOT NULL DEFAULT (strftime('%s','now')),
    updated_at       INTEGER NOT NULL DEFAULT (strftime('%s','now')),

    FOREIGN KEY (category_id)
        REFERENCES transaction_category (id)
        ON UPDATE CASCADE
        ON DELETE RESTRICT,

    FOREIGN KEY (from_account_id)
        REFERENCES account (id)
        ON UPDATE CASCADE
        ON DELETE SET NULL,

    FOREIGN KEY (to_account_id)
        REFERENCES account (id)
        ON UPDATE CASCADE
        ON DELETE SET NULL,

    -- a transaction should touch at least one account (transfer needs both,
    -- income/expense needs one side); drop this if that's not your intent
    CHECK (from_account_id IS NOT NULL OR to_account_id IS NOT NULL)
);

CREATE INDEX idx_transaction_category_id     ON "transaction" (category_id);
CREATE INDEX idx_transaction_from_account_id ON "transaction" (from_account_id);
CREATE INDEX idx_transaction_to_account_id   ON "transaction" (to_account_id);

CREATE TRIGGER trg_transaction_updated_at
AFTER UPDATE ON "transaction"
FOR EACH ROW
BEGIN
    UPDATE "transaction" SET updated_at = strftime('%s','now') WHERE id = OLD.id;
END;

-- ----------------------------------------------------------------------------
-- operation
-- ----------------------------------------------------------------------------
-- entity_id is polymorphic (genid_t): depending on entity_type it references
-- either account.id, transaction_category.id (both integer stdid_t) or
-- "transaction".id (a uuid_t). SQLite has no native polymorphic foreign key,
-- so entity_id is stored as TEXT (integers are stored as their decimal text
-- form, uuids as-is) and integrity is enforced via triggers instead of a
-- FOREIGN KEY clause.
--
-- Adjust the entity_type numeric values (0/1/2) below to match your actual
-- EntityType enum ordering.
-- ----------------------------------------------------------------------------
CREATE TABLE operation (
    id              TEXT    PRIMARY KEY CHECK (length(id) = 36),      -- uuid_t
    device_id       TEXT    NOT NULL CHECK (length(device_id) = 36),  -- uuid_t
    counter         INTEGER NOT NULL CHECK (counter >= 0),            -- uint64_t (see note below)
    description     TEXT             CHECK (description IS NULL OR length(description) <= 128),
    operation_type  INTEGER NOT NULL, -- OperationType enum (adjust CHECK to real values)
    entity_type     INTEGER NOT NULL CHECK (entity_type IN (0, 1, 2)), -- EntityType: 0=ACCOUNT,1=TRANSACTION_CATEGORY,2=TRANSACTION
    entity_id       TEXT    NOT NULL, -- genid_t: account/category id (as text) or transaction uuid
    created_at      INTEGER NOT NULL DEFAULT (strftime('%s','now')),
    updated_at      INTEGER NOT NULL DEFAULT (strftime('%s','now')),

    UNIQUE (device_id, counter)
);

CREATE INDEX idx_operation_entity ON operation (entity_type, entity_id);

CREATE TRIGGER trg_operation_updated_at
AFTER UPDATE ON operation
FOR EACH ROW
BEGIN
    UPDATE operation SET updated_at = strftime('%s','now') WHERE id = OLD.id;
END;

-- Validate the polymorphic entity_id reference on insert
CREATE TRIGGER trg_operation_validate_entity_insert
BEFORE INSERT ON operation
FOR EACH ROW
BEGIN
    SELECT CASE
        WHEN NEW.entity_type = 0
             AND NOT EXISTS (SELECT 1 FROM account WHERE id = CAST(NEW.entity_id AS INTEGER))
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing account')

        WHEN NEW.entity_type = 1
             AND NOT EXISTS (SELECT 1 FROM transaction_category WHERE id = CAST(NEW.entity_id AS INTEGER))
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing transaction_category')

        WHEN NEW.entity_type = 2
             AND NOT EXISTS (SELECT 1 FROM "transaction" WHERE id = NEW.entity_id)
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing transaction')
    END;
END;

-- Validate the polymorphic entity_id reference on update
CREATE TRIGGER trg_operation_validate_entity_update
BEFORE UPDATE ON operation
FOR EACH ROW
BEGIN
    SELECT CASE
        WHEN NEW.entity_type = 0
             AND NOT EXISTS (SELECT 1 FROM account WHERE id = CAST(NEW.entity_id AS INTEGER))
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing account')

        WHEN NEW.entity_type = 1
             AND NOT EXISTS (SELECT 1 FROM transaction_category WHERE id = CAST(NEW.entity_id AS INTEGER))
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing transaction_category')

        WHEN NEW.entity_type = 2
             AND NOT EXISTS (SELECT 1 FROM "transaction" WHERE id = NEW.entity_id)
        THEN RAISE(ABORT, 'operation.entity_id does not reference an existing transaction')
    END;
END;

-- ----------------------------------------------------------------------------
-- Helpful additional indexes
-- ----------------------------------------------------------------------------
CREATE INDEX idx_account_type      ON account (type);
CREATE INDEX idx_account_archived  ON account (archived);
CREATE INDEX idx_transaction_type  ON "transaction" (type);
CREATE INDEX idx_operation_device  ON operation (device_id);