#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include "Transaction.h"
#include <vector>
#include <iostream>

class Blockchain {
private:
    std::vector<Block> chain;
    Block createGenesisBlock();

public:
    Blockchain();
    
    void addBlock(const std::vector<Transaction>& transactions);
    bool isChainValid() const;
    void printChain() const;
    
    // Getter for chain
    const std::vector<Block>& getChain() const { return chain; }
};

#endif // BLOCKCHAIN_H
