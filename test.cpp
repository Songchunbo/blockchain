#include "Blockchain.h"
#include <iostream>
#include <cassert>

void testGenesisBlock() {
    std::cout << "Testing genesis block creation..." << std::endl;
    
    Blockchain blockchain;
    const std::vector<Block>& chain = blockchain.getChain();
    
    // Check that the chain has exactly one block initially
    assert(chain.size() == 1);
    
    // Check that the genesis block has the correct data
    const Block& genesisBlock = chain[0];
    assert(genesisBlock.getData() == "Genesis Block");
    assert(genesisBlock.getPreviousHash() == "0");
    
    // Check that the genesis block has a valid hash
    assert(!genesisBlock.getHash().empty());
    
    std::cout << "Genesis block test passed!" << std::endl;
}

void testAddBlock() {
    std::cout << "Testing add block functionality..." << std::endl;
    
    Blockchain blockchain;
    blockchain.addBlock("First block");
    blockchain.addBlock("Second block");
    
    const std::vector<Block>& chain = blockchain.getChain();
    
    // Check that the chain now has three blocks
    assert(chain.size() == 3);
    
    // Check the first added block
    const Block& firstBlock = chain[1];
    assert(firstBlock.getData() == "First block");
    assert(firstBlock.getPreviousHash() == chain[0].getHash());
    
    // Check the second added block
    const Block& secondBlock = chain[2];
    assert(secondBlock.getData() == "Second block");
    assert(secondBlock.getPreviousHash() == chain[1].getHash());
    
    std::cout << "Add block test passed!" << std::endl;
}

void testChainValidation() {
    std::cout << "Testing chain validation..." << std::endl;
    
    Blockchain blockchain;
    blockchain.addBlock("First block");
    blockchain.addBlock("Second block");
    
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
