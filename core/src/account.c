#include "account.h"
#include <stdio.h>

typedef struct AccountType {
  int id;
  char name[50];
} AccountType;

typedef struct Account {
  int id;
  char name[50];
  char note[200];
  double balance;
  
  AccountType type;
} Account;