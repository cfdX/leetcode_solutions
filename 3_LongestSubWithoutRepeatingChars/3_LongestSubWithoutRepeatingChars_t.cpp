#include <catch_all.hpp>
#include "3_LongestSubWithoutRepeatingChars.h"

namespace lc::t3 {
namespace {

//------------------------------
TEST_CASE( "3_LongestSubWithoutRepeatingChars example testcases", "[]" ) {
    const auto call = []( auto s ) {
        return Solution::lengthOfLongestSubstring( s );
    };

    SECTION( "example 1" ) {
        REQUIRE( call( "abcabcbb" ) == 3 );
    }

    SECTION( "example 2" ) {
        REQUIRE( call( "bbbbb" ) == 1 );
    }

    SECTION( "example 3" ) {
        REQUIRE( call( "pwwkew" ) == 3 );
    }

    SECTION( "example 4" ) {
        REQUIRE( call( "" ) == 0 );
    }
}

} // namespace {
} // namespace lc::t3
