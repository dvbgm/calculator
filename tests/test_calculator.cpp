#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <stdexcept>

// Объявления функций из основного файла
double add(const std::vector<double>& args);
double subtract(const std::vector<double>& args);
double multiply(const std::vector<double>& args);
double divide(const std::vector<double>& args);
std::vector<double> parse_args(const std::string& arg_str);

TEST_CASE("Addition tests") {
    SECTION("Empty input") {
        REQUIRE(add({}) == 0);
    }
    SECTION("Single number") {
        REQUIRE(add({5}) == 5);
    }
    SECTION("Multiple numbers") {
        REQUIRE(add({1, 2, 3, 4}) == 10);
    }
    SECTION("Negative numbers") {
        REQUIRE(add({-1, -2, 3}) == 0);
    }
}

TEST_CASE("Subtraction tests") {
    SECTION("Empty input") {
        REQUIRE(subtract({}) == 0);
    }
    SECTION("Single number") {
        REQUIRE(subtract({5}) == 5);
    }
    SECTION("Multiple numbers") {
        REQUIRE(subtract({10, 2, 3}) == 5);
    }
    SECTION("Negative numbers") {
        REQUIRE(subtract({-1, -2, -3}) == 4);
    }
}

TEST_CASE("Multiplication tests") {
    SECTION("Empty input") {
        REQUIRE(multiply({}) == 0);
    }
    SECTION("Single number") {
        REQUIRE(multiply({5}) == 5);
    }
    SECTION("Multiple numbers") {
        REQUIRE(multiply({2, 3, 4}) == 24);
    }
    SECTION("With zero") {
        REQUIRE(multiply({1, 2, 0, 4}) == 0);
    }
    SECTION("Negative numbers") {
        REQUIRE(multiply({-1, -2, 3}) == 6);
    }
}

TEST_CASE("Division tests") {
    SECTION("Empty input") {
        REQUIRE(divide({}) == 0);
    }
    SECTION("Single number") {
        REQUIRE(divide({5}) == 5);
    }
    SECTION("Multiple numbers") {
        REQUIRE(divide({20, 5, 2}) == 2);
    }
    SECTION("Division by zero") {
        REQUIRE_THROWS_AS(divide({1, 0}), std::runtime_error);
    }
    SECTION("Floating point result") {
        REQUIRE(divide({5, 2}) == 2.5);
    }
}

TEST_CASE("Argument parsing tests") {
    SECTION("Empty string") {
        auto args = parse_args("");
        REQUIRE(args.empty());
    }
    SECTION("Single number") {
        auto args = parse_args("3.14");
        REQUIRE(args.size() == 1);
        REQUIRE(args[0] == Approx(3.14));
    }
    SECTION("Multiple numbers") {
        auto args = parse_args("1,2,3,4.5");
        REQUIRE(args.size() == 4);
        REQUIRE(args[0] == 1);
        REQUIRE(args[3] == 4.5);
    }
    SECTION("Invalid input") {
        REQUIRE_THROWS_AS(parse_args("1,two,3"), std::runtime_error);
    }
    SECTION("Whitespace handling") {
        auto args = parse_args(" 1 , 2 , 3 ");
        REQUIRE(args.size() == 3);
        REQUIRE(args[1] == 2);
    }
}
