CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS = -lpthread
TEST_LDFLAGS = -lboost_unit_test_framework

# Цели
TARGET = calculator_server
TEST_TARGET = calculator_tests

.PHONY: all build test clean

all: build

build: $(TARGET)

$(TARGET): src/config6.cpp
	@echo "🔹 Building server..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✅ Server built. Run with: ./$(TARGET) --run"

test: $(TEST_TARGET)
	@echo "🔹 Running tests..."
	@./$(TEST_TARGET) --log_level=test_suite

$(TEST_TARGET): tests/tests.cpp src/config6.cpp
	@echo "🔹 Building tests..."
	@$(CXX) $(CXXFLAGS) -DTEST_MODE -o $@ $^ $(TEST_LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "🧹 Clean complete"
