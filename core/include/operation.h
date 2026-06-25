#ifndef OPERATION_H
#define OPERATION_H

#include <time.h>
#include <stdint.h>
#include "id.h"

typedef enum {
  OPERATION_CREATE = 0,
  OPERATION_UPDATE = 1,
  OPERATION_DELETE = 2
} OperationType;

typedef enum {
  ENTITY_ACCOUNT = 0,
  ENTITY_TRANSACTION = 1,
  ENTITY_TRANSACTION_CATEGORY = 2
} EntityType;

typedef struct {
  uuid_t id;
  uuid_t device_id;
  uint64_t counter;
  char description[128];

  OperationType operation_type;
  EntityType entity_type;
  genid_t entity_id;
  
  time_t created_at;
  time_t updated_at;      // not sure if this is needed because operations are immutable, but we can keep it for now
} Operation;

#endif // OPERATION_H