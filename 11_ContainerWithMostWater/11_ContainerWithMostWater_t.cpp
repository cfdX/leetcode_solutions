#include <catch_test_macros.hpp>
#include "11_ContainerWithMostWater.h"

namespace lc::t11 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec const& heights ) noexcept -> int {
    return Solution::maxArea( heights );
}

//------------------------------
TEST_CASE( "11_ContainerWithMostWater example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto heights = Vec{
            1, 8, 6, 2, 5, 4, 8, 3, 7
        };
        REQUIRE( callAlg( heights ) == 49 );
    }

    SECTION( "example 2" ) {
        const auto heights = Vec{
            1, 1
        };
        REQUIRE( callAlg( heights ) == 1 );
    }

    SECTION( "example 3" ) {
        const auto heights = Vec{
            4, 3, 2, 1, 4
        };
        REQUIRE( callAlg( heights ) == 16 );
    }

    SECTION( "example 4" ) {
        const auto heights = Vec{
            1, 2, 1
        };
        REQUIRE( callAlg( heights ) == 2 );
    }
}

} // namespace {
} // namespace lc::t11
