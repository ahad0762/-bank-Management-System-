#pragma once
#include <vector>
#include <memory>
#include <unordered_set>
#include "Customer.h"

class Bank {
public:
    void addCustomer(Customer* customer);
    Customer* getCustomer(const std::string& name);
    const std::vector<std::unique_ptr<Customer>>& getCustomers() const;
    bool isAccountNumberTaken(const std::string& accNumber);
    void addAccountNumber(const std::string& accNumber);
private:
    std::vector<std::unique_ptr<Customer>> customers;
    std::unordered_set<std::string> accountNumbers;
};