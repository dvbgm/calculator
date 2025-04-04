#define BOOST_TEST_MODULE CalculatorTest
#include <boost/test/included/unit_test.hpp>
#include "../src/calculator.h"

BOOST_AUTO_TEST_CASE(addition_test) {
    Calculator calc;
    BOOST_CHECK(calc.add(2, 3) == 5);
}

BOOST_AUTO_TEST_CASE(subtraction_test) {
    Calculator calc;
    BOOST_CHECK(calc.subtract(5, 3) == 2);
}

BOOST_AUTO_TEST_CASE(multiplication_test) {
    Calculator calc;
    BOOST_CHECK(calc.multiply(2, 3) == 6);
}

BOOST_AUTO_TEST_CASE(division_test) {
    Calculator calc;
    BOOST_CHECK(calc.divide(6, 3) == 2);
}

BOOST_AUTO_TEST_CASE(division_by_zero_test) {
    Calculator calc;
    BOOST_CHECK_THROW(calc.divide(1, 0), std::invalid_argument);
}
