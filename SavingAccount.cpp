#include "SavingAccount.h"

SavingsAccount::SavingsAccount(const std::string& accNumber, double balance, double interestRate)
    : Account(accNumber, balance), interestRate(interestRate) {}
