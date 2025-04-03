CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lpthread

# Основные цели
TARGET = calculator_server
TEST_TARGET = calculator_tests

# Цвета для вывода
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

.PHONY: all build test clean

all: build

build: $(TARGET)
	@echo "${GREEN}✅ Сервер собран. Запустите вручную: ./$(TARGET)${NC}"

$(TARGET): config6.cpp
	@echo "${YELLOW}🔹 Компиляция сервера...${NC}"
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: $(TEST_TARGET)
	@echo "${YELLOW}🔹 Запуск тестов...${NC}"
	@./$(TEST_TARGET) || (echo "${RED}❌ Тесты завершились с ошибками${NC}" && exit 1)

$(TEST_TARGET): config6.cpp
	@echo "${YELLOW}🔹 Компиляция тестовой версии...${NC}"
	@$(CXX) $(CXXFLAGS) -DTEST_MODE -o $@ $^ $(LDFLAGS)

clean:
	@rm -f $(TARGET) $(TEST_TARGET)
	@echo "${YELLOW}🧹 Очистка проекта завершена${NC}"
