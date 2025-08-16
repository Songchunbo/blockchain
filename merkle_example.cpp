#include "MerkleTree.h"
#include "Transaction.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "Merkle Tree Example" << std::endl;
    std::cout << "==================" << std::endl;
    
    // Create multiple transactions
    std::vector<Transaction> transactions;
    transactions.push_back(Transaction("Alice", "Bob", 10.0));
    transactions.push_back(Transaction("Bob", "Charlie", 5.0));
    transactions.push_back(Transaction("Charlie", "David", 15.0));
    transactions.push_back(Transaction("David", "Eve", 7.5));
    transactions.push_back(Transaction("Eve", "Frank", 3.2));
    
    std::cout << "Transactions:" << std::endl;
    for (size_t i = 0; i < transactions.size(); ++i) {
        std::cout << i + 1 << ". ";
        transactions[i].printTransaction();
    }
    
    // Create Merkle tree
    MerkleTree merkleTree(transactions);
    
    std::cout << "\nMerkle Root: " << merkleTree.getMerkleRoot() << std::endl;
    
    return 0;
}
