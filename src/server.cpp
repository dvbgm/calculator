#include "../include/calculator.h"
#include "../include/operations.h"
#include "../include/cpp-httplib/httplib.h"
#include <sstream>

using namespace httplib;

std::vector<double> parse_args(const std::string& arg_str) {
    std::vector<double> args;
    std::istringstream iss(arg_str);
    std::string token;
    
    while (getline(iss, token, ',')) {
        try {
            args.push_back(std::stod(token));
        } catch (...) {
            throw std::runtime_error("Invalid argument: " + token);
        }
    }
    return args;
}

std::string generate_html(const std::string& operation,
                         const std::vector<double>& args,
                         double result) {
    std::ostringstream oss;
    oss << "<!DOCTYPE html><html><head><title>Calculator</title></head><body>"
        << "<h1>Result: " << result << "</h1>"
        << "<p>Operation: " << operation << "</p>"
        << "<p>Arguments: ";
    
    for (size_t i = 0; i < args.size(); ++i) {
        if (i != 0) oss << ", ";
        oss << args[i];
    }
    
    oss << "</p></body></html>";
    return oss.str();
}

void run_calculator_server() {
    Server svr;

    svr.Get("/calculate", [](const Request& req, Response& res) {
        try {
            auto args = parse_args(req.get_param_value("args"));
            auto op = req.get_param_value("op");
            
            if (operations.find(op) == operations.end()) {
                throw std::runtime_error("Unknown operation");
            }
            
            double result = operations.at(op)(args);
            res.set_content(generate_html(op, args, result), "text/html");
        } catch (const std::exception& e) {
            res.set_content("Error: " + std::string(e.what()), "text/plain");
            res.status = 400;
        }
    });

    svr.listen("localhost", 8080);
}
