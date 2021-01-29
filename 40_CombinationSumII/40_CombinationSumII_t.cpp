#include <catch_all.hpp>
#include "40_CombinationSumII.h"

#include <algorithm>

namespace lc::t40 {
namespace {

using Vec = std::vector<int>;

//------------------------------
// отсортировали порядок чисел в каждом массиве
// и потом сам порядок массивов
// чтоб сранивать было удобно
[[nodiscard]]
auto normalized( std::vector<Vec> res ) -> std::vector<Vec> {
    for ( auto& list : res ) {
        std::sort( list.begin(), list.end() );
    }
    std::sort(
          res.begin()
        , res.end()
        , []( auto const& o1, auto const& o2 ) {
            return std::lexicographical_compare(
                  o1.begin(), o1.end()
                , o2.begin(), o2.end()
            );
        }
    );
    return res;
}

//------------------------------
[[nodiscard]]
auto callAlg( Vec nums, int target ) -> std::vector<Vec> {
    return normalized(
        Solution::combinationSum2( nums, target )
    );
}

//------------------------------
TEST_CASE( "40_CombinationSumII example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto nums = Vec{ 10, 1, 2, 7, 6, 1, 5 };
        const auto exp = std::vector<Vec>{
              { 1, 1, 6 }
            , { 1, 2, 5 }
            , { 1, 7 }
            , { 2, 6 }
        };
        REQUIRE( callAlg( nums, 8 ) == normalized( exp ) );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{ 2, 5, 2, 1, 2 };
        const auto exp = std::vector<Vec>{
              { 1, 2, 2 }
            , { 5 }
        };
        REQUIRE( callAlg( nums, 5 ) == normalized( exp ) );
    }
}

} // namespace {
} // namespace lc::t40

