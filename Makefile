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
	@echo "🔹 Сборка основного приложения..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✅ Готово: ./$(TARGET)"

test: $(TEST_TARGET)
	@echo "🔹 Запуск тестов..."
	@if ./$(TEST_TARGET); then \
		echo "✅ Все тесты пройдены!"; \
	else \
		echo "❌ Тесты завершились с ошибками!"; \
		exit 1; \
	fi

$(TEST_TARGET): $(TESTS_SRC)
	@echo "🔹 Компиляция тестов..."
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "🧹 Очистка проекта"

.PHONY: all clean test
