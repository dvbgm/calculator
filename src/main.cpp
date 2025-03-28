#include "calculator.h"
#include <crow.h>

int main() {
    crow::SimpleApp app;
    Calculator calc;

    CROW_ROUTE(app, "/calculate")
    .methods("GET"_method)([&calc](const crow::request& req) {
        try {
            float a = std::stof(req.url_params.get("a"));
            float b = std::stof(req.url_params.get("b"));
            std::string op = req.url_params.get("op");

            float result;
            if (op == "+") result = calc.add(a, b);
            else if (op == "-") result = calc.subtract(a, b);
            else if (op == "*") result = calc.multiply(a, b);
            else if (op == "/") result = calc.divide(a, b);
            else return crow::response(400, "Invalid operation");

            return crow::json::wvalue{{"result", result}};
        } catch (...) {
            return crow::response(400, "Calculation error");
        }
    });

    app.port(8080).multithreaded().run();
}
