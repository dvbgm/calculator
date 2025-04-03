#pragma once
#include <vector>
#include <stdexcept>

// Базовые арифметические операции
double add(const std::vector<double>& args);
double subtract(const std::vector<double>& args);
double multiply(const std::vector<double>& args);
double divide(const std::vector<double>& args);

// Тип операции
using Operation = std::function<double(const std::vector<double>&)>;

// Доступные операции
extern const std::map<std::string, Operation> operations;
