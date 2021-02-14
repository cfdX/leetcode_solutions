#include <catch_test_macros.hpp>
#include "7_ReverseInteger.h"

namespace lc::t7 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( int n ) -> int {
    return Solution::reverse( n );
}

//------------------------------
TEST_CASE( "7_ReverseInteger example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( 123 ) == 321 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( -123 ) == -321 );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( 120 ) == 21 );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( 0 ) == 0 );
    }
}

} // namespace {
} // namespace lc::t7
