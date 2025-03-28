CC = g++
CFLAGS = -std=c++11 -Wall -I./src
LIBS = -lboost_system -lpthread
TEST_LIBS = -lcatch2

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

all: build test

build: $(BIN_DIR)/server

$(BIN_DIR)/server: $(SRC_DIR)/main.cpp $(SRC_DIR)/calculator.cpp $(SRC_DIR)/calculator.h
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

test: $(BIN_DIR)/test_calculator

$(BIN_DIR)/test_calculator: $(TEST_DIR)/test_calculator.cpp $(SRC_DIR)/calculator.cpp $(SRC_DIR)/calculator.h
	$(CC) $(CFLAGS) $^ -o $@ $(TEST_LIBS)
	./$(BIN_DIR)/test_calculator

clean:
	rm -rf $(BIN_DIR)

.PHONY: all build test clean
