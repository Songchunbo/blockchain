#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
private:
    std::string sender;
    std::string receiver;
    double amount;
    std::string timestamp;

public:
    Transaction(const std::string& sender, const std::string& receiver, double amount);
    
    // Getters
    std::string getSender() const { return sender; }
    std::string getReceiver() const { return receiver; }
    double getAmount() const { return amount; }
    std::string getTimestamp() const { return timestamp; }
    
    // Get transaction data as string for hashing
    std::string toString() const;
    
    // Display transaction
    void printTransaction() const;
};

#endif // TRANSACTION_H
