#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct Account {
    int id;
    char name[50];
    double balance;
} Account;

#endif // ACCOUNT_H