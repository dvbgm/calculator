CXX = g++
CXXFLAGS = -std=c++17 -I. -I/usr/local/include # Путь к Crow (если установлен в /usr/local/include)
LDFLAGS = -lboost_system -lpthread  # Связывание с Boost

all: calculator_app

calculator_app: main.cpp calculator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f calculator_app
