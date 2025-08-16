# C++ Blockchain Implementation

This is a simple implementation of a blockchain in C++. It demonstrates the basic concepts of blockchain technology including blocks, hashing, and chain validation.

## Features

- Block structure with data, timestamp, and hash
- SHA-256 hashing for block integrity
- Blockchain validation to detect tampering
- Simple console output to visualize the blockchain

## Project Structure

- `Block.h` / `Block.cpp` - Block class implementation
- `Blockchain.h` / `Blockchain.cpp` - Blockchain class implementation
- `main.cpp` - Demo program
- `Makefile` - Build configuration

## Requirements

- C++11 compiler
- OpenSSL development libraries

## Building

```bash
make
```

## Running

```bash
./blockchain
```

## Running Tests

```bash
make test
./test_blockchain
```

## GitHub Actions

This repository includes a GitHub Actions workflow that automatically:
- Builds the project on Ubuntu
- Runs the blockchain demo
- Runs unit tests

The workflow is triggered on pushes and pull requests to the main/master branches.

## How It Works

1. The program creates a new blockchain with a genesis block
2. Adds several blocks with sample data
3. Prints the entire blockchain
4. Validates the blockchain integrity
5. Demonstrates tampering detection

## Code Explanation

### Block Class
- Stores data, timestamp, previous hash, and current hash
- Uses SHA-256 hashing algorithm
- Calculates hash based on block data

### Blockchain Class
- Manages a vector of blocks
- Adds new blocks to the chain
- Validates the integrity of the entire chain
- Provides methods to print the chain

## Limitations

This is a simplified implementation for educational purposes and does not include:
- Network communication
- Consensus mechanisms
- Persistent storage
- Advanced cryptographic features
- Actual data structures for transactions

## License

MIT
