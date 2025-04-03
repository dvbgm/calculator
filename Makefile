CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lboost_unit_test_framework -lpthread

# Основная программа
SRC = src/config6.cpp
TARGET = calculator_server

# Тесты
TESTS_SRC = tests/tests.cpp
TEST_TARGET = calculator_tests

# Цвета для вывода
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m

.PHONY: all build test clean

all: build test

build: $(TARGET)
	@echo "${GREEN}✅ Сервер успешно собран${NC}"
	@echo "${YELLOW}Для запуска сервера выполните: ./$(TARGET)${NC}"

$(TARGET): $(SRC)
	@echo "${YELLOW}🔹 Компиляция сервера...${NC}"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_TARGET)
	@echo "${YELLOW}🔹 Запуск тестов...${NC}"
	@if ./$(TEST_TARGET) --log_level=test_suite; then \
		echo "${GREEN}✅ Все тесты пройдены успешно${NC}"; \
	else \
		echo "${RED}❌ Тесты завершились с ошибками${NC}"; \
		exit 1; \
	fi

$(TEST_TARGET): $(TESTS_SRC)
	@echo "${YELLOW}🔹 Компиляция тестов...${NC}"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "${YELLOW}🧹 Очистка проекта завершена${NC}"
