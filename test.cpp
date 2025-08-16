#include "Blockchain.h"
#include "Transaction.h"
#include <iostream>
#include <cassert>
#include <vector>

void testGenesisBlock() {
    std::cout << "Testing genesis block creation..." << std::endl;
    
    Blockchain blockchain;
    const std::vector<Block>& chain = blockchain.getChain();
    
    // Check that the chain has exactly one block initially
    assert(chain.size() == 1);
    
    // Check that the genesis block has no transactions
    assert(chain[0].getTransactions().empty());
    assert(chain[0].getPreviousHash() == "0");
    
    // Check that the genesis block has a valid hash
    assert(!chain[0].getHash().empty());
    
    std::cout << "Genesis block test passed!" << std::endl;
}

void testAddBlock() {
    std::cout << "Testing add block functionality..." << std::endl;
    
    Blockchain blockchain;
    
    // Create transactions for first block
    std::vector<Transaction> transactions1;
    transactions1.push_back(Transaction("Alice", "Bob", 10.0));
    blockchain.addBlock(transactions1);
    
    // Create transactions for second block
    std::vector<Transaction> transactions2;
    transactions2.push_back(Transaction("Bob", "Charlie", 5.0));
    blockchain.addBlock(transactions2);
    
    const std::vector<Block>& chain = blockchain.getChain();
    
    // Check that the chain now has three blocks
    assert(chain.size() == 3);
    
    // Check the first added block
    const Block& firstBlock = chain[1];
    assert(firstBlock.getTransactions().size() == 1);
    assert(firstBlock.getPreviousHash() == chain[0].getHash());
    
    // Check the second added block
    const Block& secondBlock = chain[2];
    assert(secondBlock.getTransactions().size() == 1);
    assert(secondBlock.getPreviousHash() == chain[1].getHash());
    
    std::cout << "Add block test passed!" << std::endl;
}

void testChainValidation() {
    std::cout << "Testing chain validation..." << std::endl;
    
    Blockchain blockchain;
    
    // Create transactions for first block
    std::vector<Transaction> transactions1;
    transactions1.push_back(Transaction("Alice", "Bob", 10.0));
    blockchain.addBlock(transactions1);
    
    // Create transactions for second block
    std::vector<Transaction> transactions2;
    transactions2.push_back(Transaction("Bob", "Charlie", 5.0));
    blockchain.addBlock(transactions2);
    
    // The chain should be valid initially
    assert(blockchain.isChainValid() == true);
    
    std::cout << "Chain validation test passed!" << std::endl;
}

int main() {
    std::cout << "Running blockchain tests..." << std::endl;
    
    testGenesisBlock();
    testAddBlock();
    testChainValidation();
    
    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}
