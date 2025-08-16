CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LIBS = -lssl -lcrypto

# Main program
SRCDIR = .
SOURCES = Block.cpp Blockchain.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = blockchain

# Test program
TEST_SOURCES = Block.cpp Blockchain.cpp test.cpp
TEST_OBJECTS = Block.o Blockchain.o test.o
TEST_TARGET = test_blockchain

all: $(TARGET)

$(TARGET): Block.o Blockchain.o main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) Block.o Blockchain.o main.o $(LIBS)

test: $(TEST_TARGET)

$(TEST_TARGET): Block.o Blockchain.o test.o
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) Block.o Blockchain.o test.o $(LIBS)

Block.o: Block.cpp Block.h
	$(CXX) $(CXXFLAGS) -c Block.cpp $(LIBS)

Blockchain.o: Blockchain.cpp Blockchain.h Block.h
	$(CXX) $(CXXFLAGS) -c Blockchain.cpp $(LIBS)

main.o: main.cpp Blockchain.h Block.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(LIBS)

test.o: test.cpp Blockchain.h Block.h
	$(CXX) $(CXXFLAGS) -c test.cpp $(LIBS)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
