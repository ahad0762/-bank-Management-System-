#include "Transaction.h"

Transaction::Transaction(const std::string& description, double amount)
    : description(description), amount(amount) {
    timeStamp = std::time(nullptr); // Get current timestamp
}

std::string Transaction::getDescription() const {
    return description;
}

double Transaction::getAmount() const {
    return amount;
}

time_t Transaction::getTimeStamp() const {
    return timeStamp;
}
