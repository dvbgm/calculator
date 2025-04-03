#include "../include/operations.h"

double add(const std::vector<double>& args) {
    double result = 0;
    for (double arg : args) result += arg;
    return result;
}

double subtract(const std::vector<double>& args) {
    if (args.empty()) return 0;
    double result = args[0];
    for (size_t i = 1; i < args.size(); ++i) result -= args[i];
    return result;
}

double multiply(const std::vector<double>& args) {
    if (args.empty()) return 0;
    double result = 1;
    for (double arg : args) result *= arg;
    return result;
}

double divide(const std::vector<double>& args) {
    if (args.empty()) return 0;
    if (args.size() == 1) return args[0];
    
    double result = args[0];
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == 0) throw std::runtime_error("Division by zero");
        result /= args[i];
    }
    return result;
}

const std::map<std::string, Operation> operations = {
    {"add", add},
    {"subtract", subtract},
    {"multiply", multiply},
    {"divide", divide}
};
