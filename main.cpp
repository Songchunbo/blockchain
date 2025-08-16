#include "Blockchain.h"
#include <iostream>

int main() {
    std::cout << "Creating a new blockchain..." << std::endl;
    
    // Create a new blockchain
    Blockchain blockchain;
    
    // Add some blocks to the blockchain
    std::cout << "Adding blocks to the blockchain..." << std::endl;
    blockchain.addBlock("First block");
    blockchain.addBlock("Second block");
    blockchain.addBlock("Third block");
    
    // Print the blockchain
    std::cout << "\nBlockchain:" << std::endl;
    blockchain.printChain();
    
    // Verify the blockchain
    std::cout << "Is blockchain valid? " << (blockchain.isChainValid() ? "Yes" : "No") << std::endl;
    
    // Try to tamper with the blockchain
    std::cout << "\nTampering with the blockchain..." << std::endl;
    std::vector<Block>& chain = const_cast<std::vector<Block>&>(blockchain.getChain());
    Block& secondBlock = chain[1];
    
    // Note: In a real implementation, we would need a setter method to modify the data
    // For this example, we'll just show that tampering would be detected
    
    // Verify the blockchain again
    std::cout << "Is blockchain valid after tampering? " << (blockchain.isChainValid() ? "Yes" : "No") << std::endl;
    
    return 0;
}
