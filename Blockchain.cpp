#include "Blockchain.h"
#include <vector>

Blockchain::Blockchain() {
    // Create the genesis block
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock() {
    // Create a genesis block with no previous hash and no transactions
    std::vector<Transaction> genesisTransactions;
    return Block(genesisTransactions, "0");
}

void Blockchain::addBlock(const std::vector<Transaction>& transactions) {
    // Get the hash of the previous block
    std::string previousHash = chain.back().getHash();
    
    // Create a new block with the transactions and previous hash
    Block newBlock(transactions, previousHash);
    
    // Add the new block to the chain
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    // Check if the chain is valid
    for (size_t i = 1; i < chain.size(); ++i) {
        // Get the current block and the previous block
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];
        
        // Check if the previous hash of the current block matches the hash of the previous block
        if (currentBlock.getPreviousHash() != previousBlock.getHash()) {
            return false;
        }
        
        // Recalculate the hash of the current block and check if it matches
        std::string calculatedHash = currentBlock.calculateHash();
        if (currentBlock.getHash() != calculatedHash) {
            return false;
        }
    }
    
    return true;
}

void Blockchain::printChain() const {
    for (size_t i = 0; i < chain.size(); ++i) {
        const Block& block = chain[i];
        std::cout << "Block #" << i << std::endl;
        block.printBlock();
        std::cout << "------------------------" << std::endl;
    }
}
