# C++ Blockchain Implementation with Transactions and Merkle Trees

This is an enhanced implementation of a blockchain in C++ that includes transaction simulation and Merkle tree implementation. It demonstrates advanced concepts of blockchain technology including blocks, transactions, hashing, Merkle trees, and chain validation.

## Features

- Block structure with transactions and Merkle root
- Transaction simulation with sender, receiver, and amount
- Merkle tree implementation for transaction verification
- SHA-256 hashing for block integrity
- Blockchain validation to detect tampering
- Simple console output to visualize the blockchain

## Project Structure

- `Block.h` / `Block.cpp` - Block class implementation with transactions and Merkle root
- `Blockchain.h` / `Blockchain.cpp` - Blockchain class implementation
- `Transaction.h` / `Transaction.cpp` - Transaction class implementation
- `MerkleTree.h` / `MerkleTree.cpp` - Merkle tree implementation
- `main.cpp` - Demo program with transaction examples
- `test.cpp` - Unit tests
- `merkle_example.cpp` - Merkle tree example
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

## Running Merkle Tree Example

```bash
make merkle_example
./merkle_example
```

## GitHub Actions

This repository includes a GitHub Actions workflow that automatically:
- Builds the project on Ubuntu
- Runs the blockchain demo
- Runs unit tests

The workflow is triggered on pushes and pull requests to the main/master branches.

## How It Works

1. The program creates a new blockchain with a genesis block (no transactions)
2. Creates transactions between parties (Alice, Bob, Charlie, etc.)
3. Adds blocks with multiple transactions to the blockchain
4. Each block contains a Merkle root of its transactions
5. Prints the entire blockchain with transaction details
6. Validates the blockchain integrity
7. Demonstrates tampering detection

## Code Explanation

### Transaction Class
- Represents a transaction between two parties
- Stores sender, receiver, amount, and timestamp
- Provides methods to serialize transaction data

### MerkleTree Class
- Implements a Merkle tree for transaction verification
- Calculates the Merkle root from a list of transactions
- Uses SHA-256 hashing for all operations
- Handles both even and odd numbers of transactions

### Block Class
- Stores a list of transactions instead of simple data
- Contains a Merkle root of its transactions
- Stores previous hash, timestamp, and current hash
- Uses SHA-256 hashing algorithm
- Calculates hash based on Merkle root, previous hash, and timestamp

### Blockchain Class
- Manages a vector of blocks
- Adds new blocks with transactions to the chain
- Validates the integrity of the entire chain
- Provides methods to print the chain with transaction details

## Limitations

This is a simplified implementation for educational purposes and does not include:
- Network communication
- Consensus mechanisms
- Persistent storage
- Advanced cryptographic features
- Transaction validation (e.g., checking account balances)
- Wallet management

## License

MIT
