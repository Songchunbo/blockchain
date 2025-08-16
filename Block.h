#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include "Transaction.h"

class Block {
private:
    std::vector<Transaction> transactions;
    std::string previousHash;
    time_t timestamp;
    std::string hash;
    std::string merkleRoot;

public:
    Block(const std::vector<Transaction>& transactions, const std::string& previousHash);
    
    // Getters
    std::vector<Transaction> getTransactions() const { return transactions; }
    std::string getPreviousHash() const { return previousHash; }
    time_t getTimestamp() const { return timestamp; }
    std::string getHash() const { return hash; }
    std::string getMerkleRoot() const { return merkleRoot; }
    std::string calculateHash() const;
    
    // Print block details
    void printBlock() const;
};

#endif // BLOCK_H
