#define BOOST_TEST_MODULE CalculatorTests
#include <boost/test/unit_test.hpp>
#include "../src/config6.cpp"

BOOST_AUTO_TEST_SUITE(CalculatorTests)

BOOST_AUTO_TEST_CASE(Addition) {
    BOOST_CHECK_EQUAL(add({1, 2, 3}), 6);
    BOOST_CHECK_EQUAL(add({-1, 1}), 0);
}

BOOST_AUTO_TEST_CASE(Division) {
    BOOST_CHECK_CLOSE(divide({10, 2}), 5.0, 0.001);
    BOOST_CHECK_THROW(divide({1, 0}), runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
