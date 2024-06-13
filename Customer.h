#pragma once
#include <string>
#include <vector>
#include "Account.h"

class Customer {
public:
    Customer(const std::string& name);
    std::string getName() const;
    void addAccount(Account* account);
    Account* getAccount(const std::string& accNumber);
    std::vector<Account*> getAccounts() const;
private:
    std::string name;
    std::vector<Account*> accounts;
};
