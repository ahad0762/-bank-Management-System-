#include "Customer.h"

Customer::Customer(const std::string& name) : name(name) {}

std::string Customer::getName() const {
    return name;
}

void Customer::addAccount(Account* account) {
    accounts.push_back(account);
}

Account* Customer::getAccount(const std::string& accNumber) {
    for (auto& acc : accounts) {
        if (acc->getAccountNumber() == accNumber)
            return acc;
    }
    return nullptr;
}

std::vector<Account*> Customer::getAccounts() const {
    return accounts;
}
