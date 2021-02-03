#include <catch_test_macros.hpp>
#include "12_IntegerToRoman.h"

namespace lc::t12 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( int n )  -> std::string {
    return Solution::intToRoman( n );
}

//------------------------------
TEST_CASE( "12_IntegerToRoman example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( 3 ) == "III" );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( 4 ) == "IV" );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( 9 ) == "IX" );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( 58 ) == "LVIII" );
    }

    SECTION( "example 5" ) {
        REQUIRE( callAlg( 1994 ) == "MCMXCIV" );
    }
}

} // namespace {
} // namespace lc::t12
