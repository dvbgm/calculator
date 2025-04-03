#pragma once
#include <vector>
#include <string>
#include <map>
#include <functional>

// Объявления вспомогательных функций
std::vector<double> parse_args(const std::string& arg_str);
std::string generate_html(const std::string& operation, 
                         const std::vector<double>& args, 
                         double result);
void run_calculator_server();
