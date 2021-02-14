#include <catch_test_macros.hpp>
#include "33_SearchInRotatedSortedArray.h"

namespace lc::t33 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec const& nums, int target ) -> int {
    return Solution::search( nums, target );
}

//------------------------------
TEST_CASE( "33_SearchInRotatedSortedArray example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto nums = Vec{
            4, 5, 6, 7, 0, 1, 2
        };
        REQUIRE( callAlg( nums, 0 ) == 4 );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{
            4, 5, 6, 7, 0, 1, 2
        };
        REQUIRE( callAlg( nums, 3 ) == -1 );
    }

    SECTION( "example 3" ) {
        const auto nums = Vec{ 1 };
        REQUIRE( callAlg( nums, 0 ) == -1 );
    }
}

} // namespace {
} // namespace lc::t33
