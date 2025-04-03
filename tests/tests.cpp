 #define BOOST_TEST_MODULE CalcTests
 include <boost/test/unit_test.hpp>
 #include "../src/config6.cpp" // Подключаем исходный файл для тестирования
 
 BOOST_AUTO_TEST_SUITE(BasicOperationsTests)
 
 BOOST_AUTO_TEST_CASE(Tests) {
    BOOST_CHECK_EQUAL(add({0.5, 0.5}), 1.0);
    BOOST_CHECK_EQUAL(subtract({10, 2}), 8);
    BOOST_CHECK_EQUAL(multiply({2, 12}), 24);
    BOOST_CHECK_EQUAL(divide({10, 2}), 5);
    BOOST_CHECK_THROW(divide({10, 0}), runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
