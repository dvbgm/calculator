CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./Crow/include
LIBS = -lpthread

BOOST_DIR = /usr/lib/x86_64-linux-gnu

# Путь к исходным файлам
SRC_DIR = src
TEST_DIR = tests

# Исходники
SRC = $(SRC_DIR)/calculator.cpp $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/test_calculator.cpp src/calculator.cpp

# Исполнимая программа
TARGET = app
TEST_EXEC = test_runner

# Пути к Boost
BOOST_LIB = $(BOOST_DIR)/libboost_system.a
BOOST_INCLUDE = -I$(BOOST_DIR)/include

# Сборка приложения
all: $(TARGET)

$(TARGET): $(SRC)
        $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LIBS) $(BOOST_INCLUDE)

# Сборка тестов
test: $(TEST_SRC)
        $(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_SRC) $(BOOST_LIB) $(BOOST_INCLUDE) $(LIBS)
        ./$(TEST_EXEC)

clean:
        rm -f $(TARGET) $(TEST_EXEC)
