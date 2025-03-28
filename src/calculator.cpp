#include "calculator.h"

float Calculator::add(float a, float b) { return a + b; }
float Calculator::subtract(float a, float b) { return a - b; }
float Calculator::multiply(float a, float b) { return a * b; }

float Calculator::divide(float a, float b) {
    if (b == 0) throw "Division by zero!";
    return a / b;
}
