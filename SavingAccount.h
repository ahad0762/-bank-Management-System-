#pragma once
#include<string>
#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(const std::string& accNumber, double balance, double interestRate);
private:
    double interestRate;
};