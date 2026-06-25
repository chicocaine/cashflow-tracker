#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <time.h>
#include "currencies.h"
#include "id.h"

typedef enum {
  LIQUID = 0,
  SAVINGS = 1,
  CREDIT = 2,
  INVESTMENT = 3
} AccountType;

typedef struct {
  stdid_t id;
  char name[64];
  char note[256];
  double initial_balance;
  double current_balance;

  int archived;
  int suspended;

  AccountType type;
  Currency currency;

  time_t created_at;
  time_t updated_at;
} Account;

#endif // ACCOUNT_H