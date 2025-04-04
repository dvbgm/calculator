// main.cpp
#include "crow.h"
#include "calculator.h"
#include <string>
#include <sstream>

int main() {
    crow::SimpleApp app;
    Calculator calculator;  // Теперь используется в роутах

    CROW_ROUTE(app, "/add/<double>/<double>")
    ([&calculator](double a, double b) {
        std::ostringstream response;
        response << "Result: " << calculator.add(a, b);
        return crow::response(response.str());
    });

    CROW_ROUTE(app, "/subtract/<double>/<double>")
    ([&calculator](double a, double b) {
        std::ostringstream response;
        response << "Result: " << calculator.subtract(a, b);
        return crow::response(response.str());
    });

    CROW_ROUTE(app, "/multiply/<double>/<double>")
    ([&calculator](double a, double b) {
        std::ostringstream response;
        response << "Result: " << calculator.multiply(a, b);
        return crow::response(response.str());
    });

    CROW_ROUTE(app, "/divide/<double>/<double>")
    ([&calculator](double a, double b) {
        if (b == 0) {
            return crow::response(400, "Error: Division by zero!");
        }
        std::ostringstream response;
        response << "Result: " << calculator.divide(a, b);
        return crow::response(response.str());
    });

    app.port(8080).multithreaded().run();
}
