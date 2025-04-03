CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lboost_unit_test_framework -lpthread

# Основная программа
SRC = src/config6.cpp
TARGET = calculator_server

# Тесты
TESTS_SRC = tests/tests.cpp
TEST_TARGET = calculator_tests

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "🔹 Сборка сервера..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_TARGET)
	@echo "🔹 Запуск тестов..."
	@./$(TEST_TARGET)

$(TEST_TARGET): $(TESTS_SRC)
	@echo "🔹 Компиляция тестов..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
