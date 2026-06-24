#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <time.h>

enum AccountType {
  LIQUID = 0,
  SAVINGS = 1,
  CREDIT = 2,
  INVESTMENT = 3
};

typedef struct Account {
  int id;
  char name[50];
  char note[200];
  double balance;

  enum AccountType type;
  time_t created_at;
  time_t updated_at;
  int is_deleted;
} Account;

#endif // ACCOUNT_H