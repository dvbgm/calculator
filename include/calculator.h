#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>

// Парсинг аргументов
std::vector<double> parse_args(const std::string& arg_str);

// Генерация HTML
std::string generate_html(const std::string& operation,
                        const std::vector<double>& args,
                        double result);

// Запуск сервера
void run_calculator_server();
