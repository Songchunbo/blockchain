CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lcrypto

# Main program
SRCDIR = .
SOURCES = Block.cpp Blockchain.cpp Transaction.cpp MerkleTree.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = blockchain

# Test program
TEST_SOURCES = Block.cpp Blockchain.cpp Transaction.cpp MerkleTree.cpp test.cpp
TEST_OBJECTS = Block.o Blockchain.o Transaction.o MerkleTree.o test.o
TEST_TARGET = test_blockchain

# Merkle example
MERKLE_SOURCES = Block.cpp Blockchain.cpp Transaction.cpp MerkleTree.cpp merkle_example.cpp
MERKLE_OBJECTS = Block.o Blockchain.o Transaction.o MerkleTree.o merkle_example.o
MERKLE_TARGET = merkle_example

all: $(TARGET)

$(TARGET): Block.o Blockchain.o Transaction.o MerkleTree.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) Block.o Blockchain.o Transaction.o MerkleTree.o main.o $(LIBS)

test: $(TEST_TARGET)

$(TEST_TARGET): Block.o Blockchain.o Transaction.o MerkleTree.o test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) Block.o Blockchain.o Transaction.o MerkleTree.o test.o $(LIBS)

$(MERKLE_TARGET): Block.o Blockchain.o Transaction.o MerkleTree.o merkle_example.o
	$(CXX) $(CXXFLAGS) -o $(MERKLE_TARGET) Block.o Blockchain.o Transaction.o MerkleTree.o merkle_example.o $(LIBS)

Block.o: Block.cpp Block.h Transaction.h MerkleTree.h
	$(CXX) $(CXXFLAGS) -c Block.cpp

Blockchain.o: Blockchain.cpp Blockchain.h Block.h Transaction.h
	$(CXX) $(CXXFLAGS) -c Blockchain.cpp

Transaction.o: Transaction.cpp Transaction.h
	$(CXX) $(CXXFLAGS) -c Transaction.cpp

MerkleTree.o: MerkleTree.cpp MerkleTree.h Transaction.h
	$(CXX) $(CXXFLAGS) -c MerkleTree.cpp

main.o: main.cpp Blockchain.h Block.h Transaction.h
	$(CXX) $(CXXFLAGS) -c main.cpp

test.o: test.cpp Blockchain.h Block.h Transaction.h
	$(CXX) $(CXXFLAGS) -c test.cpp

merkle_example.o: merkle_example.cpp MerkleTree.h Transaction.h
	$(CXX) $(CXXFLAGS) -c merkle_example.cpp

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET) $(TEST_TARGET) $(MERKLE_TARGET)

.PHONY: all clean test merkle
