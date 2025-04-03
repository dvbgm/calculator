#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <sstream>
#include <cstdlib>
#include "../include/cpp-httplib/httplib.h"

using namespace httplib;
using namespace std;

// Функции для операций
double add(const vector<double>& args) {
    double result = 0;
    for (double arg : args) result += arg;
    return result;
}

double subtract(const vector<double>& args) {
    if (args.empty()) return 0;
    double result = args[0];
    for (size_t i = 1; i < args.size(); ++i) result -= args[i];
    return result;
}

double multiply(const vector<double>& args) {
    if (args.empty()) return 0;
    double result = 1;
    for (double arg : args) result *= arg;
    return result;
}

double divide(const vector<double>& args) {
    if (args.empty()) return 0;
    if (args.size() == 1) return args[0];
    double result = args[0];
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == 0) {
            throw runtime_error("Division by zero");
        }
        result /= args[i];
    }
    return result;
}

// Карта операций
map<string, function<double(const vector<double>&)>> operations = {
    {"add", add},
    {"subtract", subtract},
    {"multiply", multiply},
    {"divide", divide}
};

// Функция для парсинга аргументов
vector<double> parse_args(const string& arg_str) {
    vector<double> args;
    istringstream iss(arg_str);
    string token;
    
    while (getline(iss, token, ',')) {
        try {
            args.push_back(stod(token));
        } catch (const exception& e) {
            throw runtime_error("Invalid argument: " + token);
        }
    }
    
    return args;
}

// Генерация HTML страницы с результатом
string generate_html(const string& operation, const vector<double>& args, double result) {
    ostringstream oss;
    oss << "<!DOCTYPE html><html><head><title>Operation Result</title>"
        << "<style>body { font-family: Arial, sans-serif; margin: 40px; }"
        << "h1 { color: #333; } .result { font-size: 24px; color: #0066cc; }"
        << "</style></head><body>"
        << "<h1>Operation Result</h1>"
        << "<p><strong>Operation:</strong> " << operation << "</p>"
        << "<p><strong>Arguments:</strong> ";
    
    for (size_t i = 0; i < args.size(); ++i) {
        if (i != 0) oss << ", ";
        oss << args[i];
    }
    
    oss << "</p><p class=\"result\"><strong>Result:</strong> " << result << "</p>"
        << "</body></html>";
    
    return oss.str();
}

// Функция для запуска сервера
void run_calculator_server() {
    Server svr;

    svr.Get("/calculate", [](const Request& req, Response& res) {
        if (!req.has_param("op") || !req.has_param("args")) {
            res.set_content("Missing parameters. Usage: /calculate?op=operation&args=arg1,arg2,...", "text/plain");
            res.status = 400;
            return;
        }

        string operation = req.get_param_value("op");
        string arg_str = req.get_param_value("args");

        try {
            vector<double> args = parse_args(arg_str);
            
            if (operations.find(operation) == operations.end()) {
                throw runtime_error("Unknown operation: " + operation);
            }

            double result = operations[operation](args);
            string html = generate_html(operation, args, result);
            res.set_content(html, "text/html");
        } catch (const exception& e) {
            res.set_content("Error: " + string(e.what()), "text/plain");
            res.status = 400;
        }
    });

    svr.Get("/", [](const Request&, Response& res) {
        string html = R"(
<!DOCTYPE html>
<html>
<head>
    <title>Operation Server</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; }
        h1 { color: #333; }
        .example { background: #f5f5f5; padding: 15px; border-radius: 5px; }
    </style>
</head>
<body>
    <h1>Operation Server</h1>
    <p>This server performs basic arithmetic operations.</p>
    <h2>Usage:</h2>
    <p>Make a GET request to <code>/calculate</code> with the following parameters:</p>
    <ul>
        <li><code>op</code> - operation (add, subtract, multiply, divide)</li>
        <li><code>args</code> - comma-separated list of numbers</li>
    </ul>
    
    <h2>Examples:</h2>
    <div class="example">
        <p>Add two numbers: <a href="/calculate?op=add&args=5,3">/calculate?op=add&args=5,3</a></p>
        <p>Subtract numbers: <a href="/calculate?op=subtract&args=10,2,3">/calculate?op=subtract&args=10,2,3</a></p>
        <p>Multiply numbers: <a href="/calculate?op=multiply&args=2,3,4">/calculate?op=multiply&args=2,3,4</a></p>
        <p>Divide numbers: <a href="/calculate?op=divide&args=20,5,2">/calculate?op=divide&args=20,5,2</a></p>
    </div>
</body>
</html>
        )";
        res.set_content(html, "text/html");
    });

     cout << "Server is ready at http://localhost:8080\n";
     //cout << "Call 'run_calculator_server()' to start it\n";
}

 int main() {
     cout << "Starting calculator server...\n";
     run_calculator_server();
     return 0;
}
