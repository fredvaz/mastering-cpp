
// Unit Tests Executable

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() function

#include <catch2/catch.hpp>

// We must include our Library
#include "my_lib.h"


TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}

// A Second Test Case as example
TEST_CASE( "logs are computed", "[log]" ) {
    REQUIRE( factorial(0) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}