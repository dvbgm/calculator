#define BOOST_TEST_MODULE CalculatorTests
#include <boost/test/unit_test.hpp>
#include "../include/operations.h"

BOOST_AUTO_TEST_SUITE(OperationsTests)

BOOST_AUTO_TEST_CASE(TestAdd) {
    BOOST_CHECK_EQUAL(add({1, 2, 3}), 6);
    BOOST_CHECK_EQUAL(add({-1, 1}), 0);
}

BOOST_AUTO_TEST_CASE(TestDivide) {
    BOOST_CHECK_EQUAL(divide({10, 2}), 5);
    BOOST_CHECK_THROW(divide({10, 0}), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
