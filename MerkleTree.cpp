#include "MerkleTree.h"
#include <openssl/evp.h>
#include <iomanip>
#include <iostream>
#include <sstream>

MerkleTree::MerkleTree(const std::vector<Transaction>& transactions) {
    // Calculate hash for each transaction
    for (const auto& transaction : transactions) {
        std::string transactionData = transaction.toString();
        
        // Hash the transaction data
        unsigned char hash[EVP_MAX_MD_SIZE];
        unsigned int hashLen;
        
        const EVP_MD* md = EVP_sha256();
        EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
        EVP_DigestInit_ex(mdctx, md, NULL);
        EVP_DigestUpdate(mdctx, transactionData.c_str(), transactionData.size());
        EVP_DigestFinal_ex(mdctx, hash, &hashLen);
        EVP_MD_CTX_free(mdctx);
        
        std::stringstream ssHash;
        for (unsigned int i = 0; i < hashLen; ++i) {
            ssHash << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        
        transactionsHashes.push_back(ssHash.str());
    }
    
    // Build the Merkle tree
    buildTree();
}

std::string MerkleTree::calculateHash(const std::string& first, const std::string& second) const {
    std::string combined = first + second;
    
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen;
    
    const EVP_MD* md = EVP_sha256();
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, combined.c_str(), combined.size());
    EVP_DigestFinal_ex(mdctx, hash, &hashLen);
    EVP_MD_CTX_free(mdctx);
    
    std::stringstream ssHash;
    for (unsigned int i = 0; i < hashLen; ++i) {
        ssHash << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ssHash.str();
}

void MerkleTree::buildTree() {
    if (transactionsHashes.empty()) {
        merkleRoot = "";
        return;
    }
    
    // If there's only one transaction, the Merkle root is its hash
    if (transactionsHashes.size() == 1) {
        merkleRoot = transactionsHashes[0];
        return;
    }
    
    // Create a copy of the transaction hashes to work with
    std::vector<std::string> currentLevel = transactionsHashes;
    
    // Build the tree level by level
    while (currentLevel.size() > 1) {
        std::vector<std::string> nextLevel;
        
        // Process pairs of hashes
        for (size_t i = 0; i < currentLevel.size(); i += 2) {
            if (i + 1 < currentLevel.size()) {
                // Combine two hashes
                std::string combinedHash = calculateHash(currentLevel[i], currentLevel[i + 1]);
                nextLevel.push_back(combinedHash);
            } else {
                // If odd number of elements, duplicate the last one
                std::string combinedHash = calculateHash(currentLevel[i], currentLevel[i]);
                nextLevel.push_back(combinedHash);
            }
        }
        
        currentLevel = nextLevel;
    }
    
    // The final remaining hash is the Merkle root
    merkleRoot = currentLevel[0];
}

void MerkleTree::printMerkleTree() const {
    std::cout << "Merkle Root: " << merkleRoot << std::endl;
}
