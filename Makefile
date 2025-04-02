CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS = -lpthread

# Основная программа
SRC_DIR = src
SRC = $(SRC_DIR)/config6.cpp
TARGET = calculator_server

# Тесты
TESTS_DIR = tests
TESTS_SRC = $(TESTS_DIR)/tests.cpp
TEST_TARGET = calculator_tests

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "🔹 Сборка сервера..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_TARGET)
	@echo "🔹 Запуск тестов..."
	@./$(TEST_TARGET) && echo "✅ Все тесты пройдены!" || (echo "❌ Тесты упали!"; exit 1)

$(TEST_TARGET): $(TESTS_SRC)
	@echo "🔹 Компиляция тестов..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
