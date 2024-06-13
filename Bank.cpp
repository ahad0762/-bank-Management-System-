#include "Bank.h"

void Bank::addCustomer(Customer* customer) {
    customers.push_back(std::unique_ptr<Customer>(customer));
}

Customer* Bank::getCustomer(const std::string& name) {
    for (auto& cust : customers) {
        if (cust->getName() == name)
            return cust.get();
    }
    return nullptr;
}

const std::vector<std::unique_ptr<Customer>>& Bank::getCustomers() const {
    return customers;
}

bool Bank::isAccountNumberTaken(const std::string& accNumber) {
    return accountNumbers.find(accNumber) != accountNumbers.end();
}

void Bank::addAccountNumber(const std::string& accNumber) {
    accountNumbers.insert(accNumber);
}
