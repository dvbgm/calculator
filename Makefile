CC = g++
CFLAGS = -std=c++17 -Wall -I$(SRC_DIR) -I/usr/local/include/crow
LIBS = -lboost_system -lboost_filesystem -lpthread
TEST_LIBS =  # Пусто для Catch2

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

all: build test

build: $(BIN_DIR)/calculator_server

$(BIN_DIR)/calculator_server: $(SRC_DIR)/main.cpp $(SRC_DIR)/calculator.cpp $(SRC_DIR)/calculator.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

test: $(BIN_DIR)/calculator_tests
	./$(BIN_DIR)/calculator_tests

$(BIN_DIR)/calculator_tests: $(TEST_DIR)/test_calculator.cpp $(SRC_DIR)/calculator.cpp $(SRC_DIR)/calculator.h
	$(CC) $(CFLAGS) $^ -o $@ $(TEST_LIBS)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all build test clean
