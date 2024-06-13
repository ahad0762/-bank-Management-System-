#include "Account.h"

Account::Account(const std::string& accNumber, double balance)
    : accountNumber(accNumber), balance(balance) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}
