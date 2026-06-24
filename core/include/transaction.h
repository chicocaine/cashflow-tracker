#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <time.h>
#include "account.h"

enum TransactionType {
  INCOME = 0,
  EXPENSE = 1,
  TRANSFER = 2
};

typedef struct TransactionCategory {
  int id;
  char name[50];
  
  time_t created_at;
  time_t updated_at;
  int is_deleted;
} TransactionCategory;

typedef struct Transaction {
  int uuid;
  char description[100];
  char note[200];
  double amount;
  int device_id;
  
  struct Account account;
  struct TransactionCategory category;
  enum TransactionType type;
  
  time_t  created_at;
  time_t  updated_at;
  int is_deleted;
} Transaction;

#endif // TRANSACTION_H