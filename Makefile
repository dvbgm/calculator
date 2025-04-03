# Компилятор
CXX := g++

# Флаги компиляции
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude -Iinclude/cpp-httplib

# Флаги линковки
LDFLAGS := -lboost_unit_test_framework -lpthread

# Пути к файлам
SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

# Исходные файлы
SRC := $(SRC_DIR)/config6.cpp
TEST_SRC := $(TEST_DIR)/tests.cpp

# Целевые файлы
TARGET := $(BUILD_DIR)/config6
TEST_TARGET := $(BUILD_DIR)/test_config6

# Основные цели
.PHONY: all test clean

all: $(TARGET)

test: $(TEST_TARGET)
	@echo "🚀 Запуск тестов..."
	@./$(TEST_TARGET) --log_level=test_suite

$(TARGET): $(SRC) | $(BUILD_DIR)
	@echo "🔨 Сборка основного приложения..."
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	@echo "✅ Собрано: $@"

$(TEST_TARGET): $(TEST_SRC) $(SRC) | $(BUILD_DIR)
	@echo "🧪 Компиляция тестов..."
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "✅ Тесты собраны: $@"

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "🧹 Очистка завершена"
