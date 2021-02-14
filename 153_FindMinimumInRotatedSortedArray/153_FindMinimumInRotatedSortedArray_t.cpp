#include <catch_test_macros.hpp>
#include "153_FindMinimumInRotatedSortedArray.h"

namespace lc::t153 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec const& nums ) -> int {
    return Solution::findMin( nums );
}

//------------------------------
TEST_CASE( "153_FindMinimumInRotatedSortedArray example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto nums = Vec{
            3, 4, 5, 1, 2
        };
        REQUIRE( callAlg( nums ) == 1 );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{
            4, 5, 6, 7, 0, 1, 2
        };
        REQUIRE( callAlg( nums ) == 0 );
    }

    SECTION( "example 3" ) {
        const auto nums = Vec{
            11, 13, 15, 17
        };
        REQUIRE( callAlg( nums ) == 11 );
    }
}

//------------------------------
TEST_CASE( "153_FindMinimumInRotatedSortedArray my testcases", "[]" ) {
    SECTION( "case 1" ) {
        const auto nums = Vec{
            3, 4, 5, 6, 1, 2
        };
        REQUIRE( callAlg( nums ) == 1 );
    }

    SECTION( "case 2 (sorted)" ) {
        const auto nums = Vec{
            4, 5, 6, 7, 9
        };
        REQUIRE( callAlg( nums ) == 4 );
    }

    SECTION( "case 3 (one element)" ) {
        const auto nums = Vec{ 11 };
        REQUIRE( callAlg( nums ) == 11 );
    }

    SECTION( "case 4 (two elements)" ) {
        const auto nums = Vec{ 11, 12 };
        REQUIRE( callAlg( nums ) == 11 );
    }

    SECTION( "case 5 (two elements)" ) {
        const auto nums = Vec{ 12, 11 };
        REQUIRE( callAlg( nums ) == 11 );
    }

    SECTION( "case 6 (duplicates)" ) {
        const auto nums = Vec{ 12, 11, 12, 12, 12 };
        REQUIRE( callAlg( nums ) == 11 );
    }

    SECTION( "case 7" ) {
        const auto nums = Vec{ 3, 1, 2 };
        REQUIRE( callAlg( nums ) == 1 );
    }

    SECTION( "case 8" ) {
        const auto nums = Vec{ 4, 5, 1, 2, 3 };
        REQUIRE( callAlg( nums ) == 1 );
    }
}

} // namespace {
} // namespace lc::t153
