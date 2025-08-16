#include "Block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

Block::Block(const std::string& data, const std::string& previousHash) 
    : data(data), previousHash(previousHash) {
    timestamp = time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << data << previousHash << timestamp;
    
    std::string input = ss.str();
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    
    std::stringstream ssHash;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ssHash << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    
    return ssHash.str();
}
