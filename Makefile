CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS := -lboost_unit_test_framework -lpthread

SRC_DIR := src
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TARGET := $(BUILD_DIR)/calculator
TEST_TARGET := $(BUILD_DIR)/test_calculator

.PHONY: all test clean

all: $(TARGET)

test: $(TEST_TARGET)
	@./$(TEST_TARGET)

$(TARGET): $(filter-out $(BUILD_DIR)/test_%,$(OBJS))
	$(CXX) $^ -o $@ $(LDFLAGS)

$(TEST_TARGET): $(filter-out $(BUILD_DIR)/config6.o,$(OBJS))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
