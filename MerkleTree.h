#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <vector>
#include <string>
#include "Transaction.h"

class MerkleTree {
private:
    std::vector<std::string> transactionsHashes;
    std::string merkleRoot;
    
    // Helper function to calculate hash of two strings
    std::string calculateHash(const std::string& first, const std::string& second) const;
    
    // Build the Merkle tree
    void buildTree();
    
public:
    MerkleTree(const std::vector<Transaction>& transactions);
    
    // Get the Merkle root
    std::string getMerkleRoot() const { return merkleRoot; }
    
    // Display the Merkle tree structure
    void printMerkleTree() const;
};

#endif // MERKLE_TREE_H
