#define BOOST_TEST_MODULE CalculatorTests
#include <boost/test/unit_test.hpp>
#include "../src/config6.cpp"  // Подключаем тестируемый код

BOOST_AUTO_TEST_CASE(AdditionTest) {
    std::vector<double> args = {1, 2, 3};
    BOOST_CHECK_EQUAL(add(args), 6);
}

BOOST_AUTO_TEST_CASE(DivisionByZeroTest) {
    std::vector<double> args = {1, 0};
    BOOST_CHECK_THROW(divide(args), std::runtime_error);
}
