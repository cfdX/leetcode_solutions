#include <catch_test_macros.hpp>
#include "9_PalindromeNumber.h"

namespace lc::t9 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( int n ) -> bool {
    return Solution::isPalindrome( n );
}

//------------------------------
TEST_CASE( "9_PalindromeNumber example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( 121 ) == true );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( -121 ) == false );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( 10 ) == false );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( -101 ) == false );
    }
}

} // namespace {
} // namespace lc::t9
