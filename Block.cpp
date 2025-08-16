#include "Block.h"
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>

Block::Block(const std::string& data, const std::string& previousHash) 
    : data(data), previousHash(previousHash) {
    timestamp = time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << data << previousHash << timestamp;
    
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
