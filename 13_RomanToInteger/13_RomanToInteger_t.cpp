#include <catch_test_macros.hpp>
#include "13_RomanToInteger.h"

namespace lc::t13 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& str ) -> int {
    return Solution::romanToInt( str );
}

//------------------------------
TEST_CASE( "13_RomanToInteger example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( "III" ) == 3 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( "IV" ) == 4 );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( "IX" ) == 9 );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( "LVIII" ) == 58 );
    }

    SECTION( "example 5" ) {
        REQUIRE( callAlg( "MCMXCIV" ) == 1994 );
    }
}

} // namespace {
} // namespace lc::t13
