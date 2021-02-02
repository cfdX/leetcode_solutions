#include <catch_all.hpp>
#include "42_TrappingRainWater.h"

#include <algorithm>

namespace lc::t42 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec heights ) -> int {
    const auto sum1 = Solution::trap( heights );
    // для увеличения числа тестовых кейсов
    // проверяем еще для развернутого массива
    std::reverse( heights.begin(), heights.end() );
    const auto sum2 = Solution::trap( heights );
    REQUIRE( sum1 == sum2 );
    return sum1;
}

//------------------------------
TEST_CASE( "42_TrappingRainWater example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto heights = Vec{
            0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1
        };
        REQUIRE( callAlg( heights ) == 6 );
    }

    SECTION( "example 2" ) {
        const auto heights = Vec{
            4, 2, 0, 3, 2, 5
        };
        REQUIRE( callAlg( heights ) == 9 );
    }
}

//------------------------------
TEST_CASE( "42_TrappingRainWater corner cases", "[]" ) {
    REQUIRE( callAlg( {} ) == 0 );
    REQUIRE( callAlg( {1} ) == 0 );
    REQUIRE( callAlg( { 2, 2 } ) == 0 );
}

} // namespace {
} // namespace lc::t42

