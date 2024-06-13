#pragma once
#pragma once
#include <string>
#include <ctime>

class Transaction {
public:
    Transaction(const std::string& description, double amount);
    std::string getDescription() const;
    double getAmount() const;
    time_t getTimeStamp() const; // Use time_t for timestamp, or std::chrono for C++11 onwards
private:
    std::string description;
    double amount;
    time_t timeStamp;
};