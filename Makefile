# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++11 -Wall -I./include -I./include/cpp-httplib

# Флаги линковки (Boost.Test + возможные другие зависимости)
LDFLAGS = -lboost_unit_test_framework -lpthread

# Пути к исходным файлам
SRC_DIR = src
TEST_DIR = tests
INCLUDE_DIR = include

# Исходные файлы
SRC = $(SRC_DIR)/config6.cpp
TEST_SRC = $(TEST_DIR)/tests.cpp

# Имена исполняемых файлов
TARGET = config6
TEST_TARGET = test_config6

# Основные цели
all: $(TARGET) test

$(TARGET): $(SRC)
	@echo "🔨 Сборка основного приложения..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "✅ Основное приложение собрано: ./$(TARGET)"

$(TEST_TARGET): $(TEST_SRC) $(SRC)
	@echo "🧪 Компиляция тестов..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "✅ Тестовый модуль собран: ./$(TEST_TARGET)"

test: $(TEST_TARGET)
	@echo "🚀 Запуск тестов..."
	@./$(TEST_TARGET) --log_level=test_suite || (echo "❌ Тесты завершились с ошибками!"; exit 1)
	@echo "✔ Все тесты пройдены успешно!"

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "🧹 Удалены скомпилированные файлы"

.PHONY: all test clean
