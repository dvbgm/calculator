#define BOOST_TEST_MODULE Tests
#include <boost/test/unit_test.hpp>
#include "../src/config6.cpp" // Подключаем исходный файл для тестирования

BOOST_AUTO_TEST_SUITE(BasicOperationsTests)

// Тесты для функции add
BOOST_AUTO_TEST_CASE(TestAdd) {
    BOOST_CHECK_EQUAL(add({1, 2, 3}), 6);
    BOOST_CHECK_EQUAL(add({-1, 1}), 0);
    BOOST_CHECK_EQUAL(add({}), 0);
    BOOST_CHECK_EQUAL(add({0.5, 0.5}), 1.0);
}

// Тесты для функции subtract
BOOST_AUTO_TEST_CASE(TestSubtract) {
    BOOST_CHECK_EQUAL(subtract({10, 2, 3}), 5);
    BOOST_CHECK_EQUAL(subtract({5}), 5);
    BOOST_CHECK_EQUAL(subtract({0, 0}), 0);
    BOOST_CHECK_EQUAL(subtract({1.5, 0.5}), 1.0);
}

// Тесты для функции multiply
BOOST_AUTO_TEST_CASE(TestMultiply) {
    BOOST_CHECK_EQUAL(multiply({2, 3, 4}), 24);
    BOOST_CHECK_EQUAL(multiply({}), 0);
    BOOST_CHECK_EQUAL(multiply({5}), 5);
    BOOST_CHECK_EQUAL(multiply({0.5, 0.5}), 0.25);
}

// Тесты для функции divide
BOOST_AUTO_TEST_CASE(TestDivide) {
    BOOST_CHECK_EQUAL(divide({10, 2}), 5);
    BOOST_CHECK_EQUAL(divide({5}), 5);
    BOOST_CHECK_EQUAL(divide({1.0, 2.0}), 0.5);
    
    // Проверка деления на ноль
    BOOST_CHECK_THROW(divide({10, 0}), runtime_error);
    BOOST_CHECK_THROW(divide({10, 2, 0}), runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
