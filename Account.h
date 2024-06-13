#pragma once
#include<iostream>
#include<string>
class Account {
public:
    Account(const std::string& accNumber, double balance);
    virtual ~Account() = default;
    std::string getAccountNumber() const;
    double getBalance() const;
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);
protected:
    void setBalance(double newBalance);
private:
    std::string accountNumber;
    double balance;
};