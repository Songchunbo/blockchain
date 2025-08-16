#include "Transaction.h"
#include <sstream>
#include <ctime>
#include <iomanip>

Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {
    // Get current time as string
    time_t now = time(0);
    timestamp = std::to_string(now);
}

std::string Transaction::toString() const {
    std::stringstream ss;
    ss << sender << receiver << amount << timestamp;
    return ss.str();
}

void Transaction::printTransaction() const {
    std::cout << "From: " << sender << " To: " << receiver << " Amount: " << amount << " Timestamp: " << timestamp << std::endl;
}
