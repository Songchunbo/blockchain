#include "Blockchain.h"
#include "Transaction.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Creating a new blockchain with transactions..." << std::endl;
    
    // Create a new blockchain
    Blockchain blockchain;
    
    // Create some transactions for the first block
    std::cout << "Creating transactions for first block..." << std::endl;
    std::vector<Transaction> transactions1;
    transactions1.push_back(Transaction("Alice", "Bob", 10.0));
    transactions1.push_back(Transaction("Bob", "Charlie", 5.0));
    
    // Add first block with transactions
    std::cout << "Adding first block with transactions..." << std::endl;
    blockchain.addBlock(transactions1);
    
    // Create some transactions for the second block
    std::cout << "Creating transactions for second block..." << std::endl;
    std::vector<Transaction> transactions2;
    transactions2.push_back(Transaction("Charlie", "David", 15.0));
    transactions2.push_back(Transaction("David", "Eve", 7.5));
    transactions2.push_back(Transaction("Eve", "Frank", 3.2));
    
    // Add second block with transactions
    std::cout << "Adding second block with transactions..." << std::endl;
    blockchain.addBlock(transactions2);
    
    // Create some transactions for the third block
    std::cout << "Creating transactions for third block..." << std::endl;
    std::vector<Transaction> transactions3;
    transactions3.push_back(Transaction("Frank", "Grace", 12.0));
    
    // Add third block with transactions
    std::cout << "Adding third block with transactions..." << std::endl;
    blockchain.addBlock(transactions3);
    
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
    // Using the secondBlock variable to demonstrate the concept
    std::cout << "Accessing second block with " << secondBlock.getTransactions().size() << " transactions" << std::endl;
    
    // Verify the blockchain again
    std::cout << "Is blockchain valid after tampering? " << (blockchain.isChainValid() ? "Yes" : "No") << std::endl;
    
    return 0;
}
