#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/calculator.h"

TEST_CASE("Calculator operations", "[calc]") {
    Calculator calc;

    SECTION("Addition") {
        REQUIRE(calc.add(2, 3) == 5);
        REQUIRE(calc.add(-1, 1) == 0);
    }

    SECTION("Division") {
        REQUIRE(calc.divide(6, 3) == 2.0f);
        REQUIRE_THROWS_AS(calc.divide(1, 0), const char*);
    }
}
