#include <catch_test_macros.hpp>
#include "5_LongestPalindromicSubstring.h"

namespace lc::t5 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& str ) -> std::string {
    return Solution::longestPalindrome( str );
}

//------------------------------
TEST_CASE( "5_LongestPalindromicSubstring example testcases", "[]" ) {
    SECTION( "example 1" ) {
        // Note: "aba" is also a valid answer.
        REQUIRE( callAlg( "babad" ) == "bab" );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( "cbbd" ) == "bb" );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( "a" ) == "a" );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( "ac" ) == "a" );
    }
}

//------------------------------
TEST_CASE( "5_LongestPalindromicSubstring my testcases", "[]" ) {
    REQUIRE( callAlg( "bdabad" ) == "dabad" );
    REQUIRE( callAlg( "cbbcd" ) == "cbbc" );
    REQUIRE( callAlg( "" ) == "" );
}

} // namespace {
} // namespace lc::t5

