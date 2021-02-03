#include <catch_test_macros.hpp>
#include "8_StringToIntegerAtoi.h"

namespace lc::t8 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& n ) noexcept -> int {
    return Solution::myAtoi( n );
}

//------------------------------
TEST_CASE( "8_StringToIntegerAtoi example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( "42" ) == 42 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( "   -42" ) == -42 );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( "4193 with words" ) == 4193 );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( "words and 987" ) == 0 );
    }

    SECTION( "example 5" ) {
        REQUIRE( callAlg( "-91283472332" ) == -2147483648 );
    }
}

} // namespace {
} // namespace lc::t8
