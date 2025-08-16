#include "Block.h"
#include "MerkleTree.h"
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>

Block::Block(const std::vector<Transaction>& transactions, const std::string& previousHash) 
    : transactions(transactions), previousHash(previousHash) {
    timestamp = time(nullptr);
    
    // Create Merkle tree and get root
    MerkleTree merkleTree(transactions);
    merkleRoot = merkleTree.getMerkleRoot();
    
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << merkleRoot << previousHash << timestamp;
    
    std::string input = ss.str();
    
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen;
    
    const EVP_MD* md = EVP_sha256();
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(mdctx, hash, &hashLen);
    EVP_MD_CTX_free(mdctx);
    
    std::stringstream ssHash;
    for (unsigned int i = 0; i < hashLen; ++i) {
        ssHash << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ssHash.str();
}

void Block::printBlock() const {
    std::cout << "Merkle Root: " << merkleRoot << std::endl;
    std::cout << "Previous Hash: " << previousHash << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Hash: " << hash << std::endl;
    std::cout << "Transactions:" << std::endl;
    for (const auto& transaction : transactions) {
        transaction.printTransaction();
    }
}
