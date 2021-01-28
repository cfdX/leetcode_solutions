#include <catch_all.hpp>
#include "45_JumpGameII.h"

namespace lc::t45 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec const& nums ) noexcept -> int {
    return Solution::jump( nums );
}

//------------------------------
TEST_CASE( "45_JumpGameII example testcases", "[]" ) {
    SECTION( "example 1" ) {
        // The minimum number of jumps to reach the last index is 2.
        // Jump 1 step from index 0 to 1, then 3 steps to the last index.
        REQUIRE( callAlg( { 2, 3, 1, 1, 4 } ) == 2 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( { 2, 3, 0, 1, 4 } ) == 2 );
    }
}

//------------------------------
TEST_CASE( "45_JumpGameII my testcases", "[]" ) {
    SECTION( "empty vector" ) {
        REQUIRE( callAlg( {} ) == 0 );
    }
    SECTION( "one element " ) {
        REQUIRE( callAlg( {0} ) == 0 );
        REQUIRE( callAlg( {1} ) == 0 );
    }
    SECTION( "three steps" ) {
        const auto nums = Vec{ 3, 2, 2, 2, 1, 5, 1, 1, 1, 1, 1 };
        REQUIRE( callAlg( nums ) == 3 );
    }
    SECTION( "three steps with zero" ) {
        const auto nums = Vec{ 3, 2, 2, 2, 3, 0, 5, 1, 1, 1, 1, 1 };
        REQUIRE( callAlg( nums ) == 4 );
    }
    SECTION( "with dead path" ) {
        const auto nums = Vec{ 4, 2, 1, 0, 3, 0 };
        REQUIRE( callAlg( nums ) == 2 );
    }

    SECTION( "with dead path" ) {
        const auto nums = Vec{ 3, 2, 4, 2, 0, 3, 0, 1 };
        REQUIRE( callAlg( nums ) == 3 );
    }
}

} // namespace {
} // namespace lc::t45

