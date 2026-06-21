#include <iostream>
#include "account.h"

int main() {
    Account acc = {1, "John Doe", 1000.0};
    std::cout << "Account ID: " << acc.id << std::endl;
    std::cout << "Account Name: " << acc.name << std::endl;
    std::cout << "Account Balance: " << acc.balance << std::endl;
    return 0;
}