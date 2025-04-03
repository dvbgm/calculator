#define BOOST_TEST_MODULE CalculatorTests
#include <boost/test/unit_test.hpp>
#include "../src/config6.cpp"

BOOST_AUTO_TEST_SUITE(CalculatorTests)

BOOST_AUTO_TEST_CASE(Addition) {
    BOOST_CHECK_EQUAL(add({1, 2, 3}), 6);
    BOOST_CHECK_EQUAL(add({-1, 1}), 0);
}

BOOST_AUTO_TEST_CASE(Subtraction) {
    BOOST_CHECK_EQUAL(subtract({10, 2, 3}), 5);
}

BOOST_AUTO_TEST_CASE(Multiplication) {
    BOOST_CHECK_EQUAL(multiply({2, 3, 4}), 24);
}

BOOST_AUTO_TEST_CASE(Division) {
    BOOST_CHECK_CLOSE(divide({10, 2}), 5.0, 0.001);
    BOOST_CHECK_THROW(divide({1, 0}), runtime_error);
}

BOOST_AUTO_TEST_CASE(ArgumentParsing) {
    auto args = parse_args("1.5,2,3.7");
    BOOST_CHECK_EQUAL(args.size(), 3);
    BOOST_CHECK_CLOSE(args[0], 1.5, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()
