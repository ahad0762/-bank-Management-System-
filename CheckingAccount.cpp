#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& accNumber, double balance, double overdraftLimit)
    : Account(accNumber, balance), overdraftLimit(overdraftLimit) {}

bool CheckingAccount::withdraw(double amount) {
    if (getBalance() + overdraftLimit >= amount) {
        setBalance(getBalance() - amount);
        return true;
    }
    return false;
}
