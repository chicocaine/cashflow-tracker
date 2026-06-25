#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <time.h>
#include "account.h"
#include "currencies.h"
#include "id.h"

typedef enum {
  INCOME = 0,
  EXPENSE = 1,
  TRANSFER = 2
} TransactionType;

typedef struct {
  stdid_t id;
  char name[64];
  char description[128];
  
  time_t created_at;
  time_t updated_at;
  int archived;
} TransactionCategory;

typedef struct {
  uuid_t id;
  char description[128];
  char note[256];
  double amount;
  
  TransactionType type;
  int category_id;
  Currency currency;

  int archived;

  int from_account_id;
  int to_account_id;

  time_t  created_at;
  time_t  updated_at;
} Transaction;

#endif // TRANSACTION_H