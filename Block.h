#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

class Block {
private:
    std::string data;
    std::string previousHash;
    time_t timestamp;
    std::string hash;

public:
    Block(const std::string& data, const std::string& previousHash);
    
    // Getters
    std::string getData() const { return data; }
    std::string getPreviousHash() const { return previousHash; }
    time_t getTimestamp() const { return timestamp; }
    std::string getHash() const { return hash; }
    std::string calculateHash() const;
};

#endif // BLOCK_H
