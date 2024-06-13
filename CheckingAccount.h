#pragma once
#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(const std::string& accNumber, double balance, double overdraftLimit);
    bool withdraw(double amount) override;
private:
    double overdraftLimit;
};