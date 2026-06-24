#include "account.h"
#include <time.h>

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
  
  struct Account account;
  enum TransactionType type;
  struct TransactionCategory category;
  
  time_t created_at;
  time_t updated_at;
  int is_deleted;
} Transaction;