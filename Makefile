# Компилятор
CXX := g++

# Флаги компиляции
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude -Iinclude/cpp-httplib

# Флаги линковки
LDFLAGS := -lboost_unit_test_framework -lpthread

# Пути
BUILD_DIR := build

# Основные цели
.PHONY: all test clean

all: $(BUILD_DIR)/config6

test: $(BUILD_DIR)/test_config6
	@echo "🚀 Запуск тестов..."
	@./$(BUILD_DIR)/test_config6 --log_level=test_suite

$(BUILD_DIR)/config6: src/config6.cpp | $(BUILD_DIR)
	@echo "🔨 Сборка основного приложения..."
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	@echo "✅ Собрано: $@"

$(BUILD_DIR)/test_config6: tests/tests.cpp | $(BUILD_DIR)
	@echo "🧪 Компиляция тестов..."
	$(CXX) $(CXXFLAGS) -DMAIN_DISABLED $< -o $@ $(LDFLAGS)
	@echo "✅ Тесты собраны: $@"

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "🧹 Очистка завершена"
