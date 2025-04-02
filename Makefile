CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I.
LDFLAGS = -lpthread

SRC = main.cpp
TARGET = calculator_server
TEST_TARGET = calculator_tests

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): tests.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
