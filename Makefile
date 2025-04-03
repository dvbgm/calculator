CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS = -lpthread
TEST_LDFLAGS = -lboost_unit_test_framework

# Исходные файлы
SRC = src/config6.cpp
TEST_SRC = tests/tests.cpp

# Имена исполняемых файлов
TARGET = calculator
TEST_TARGET = test_calculator

all: $(TARGET) test
	@echo "✅ Образ успешно собран"

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "🔧 Собран основной исполняемый файл: $(TARGET)"

$(TEST_TARGET): $(TEST_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "🧪 Собран тестовый модуль: $(TEST_TARGET)"

test: $(TEST_TARGET)
	@echo "🚀 Запуск тестов..."
	@./$(TEST_TARGET) --log_level=test_suite || (echo "❌ Тесты не прошли"; exit 1)
	@echo "✅ Все тесты успешно пройдены"

clean:
	rm -f $(TARGET) $(TEST_TARGET)
	@echo "🧹 Очистка скомпилированных файлов"

.PHONY: all test clean
