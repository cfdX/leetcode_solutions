#include <catch_test_macros.hpp>
#include "39_CombinationSum.h"

#include <algorithm>

namespace lc::t39 {
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
        Solution::combinationSum( nums, target )
    );
}

//------------------------------
TEST_CASE( "39_CombinationSum example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto nums = Vec{ 2, 3, 6, 7 };
        const auto exp = std::vector<Vec>{
              { 2, 2, 3 }
            , { 7 }
        };
        REQUIRE( callAlg( nums, 7 ) == normalized( exp ) );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{ 2, 3, 5 };
        const auto exp = std::vector<Vec>{
              { 2, 2, 2, 2 }
            , { 2, 3, 3}
            , { 3, 5 }
        };
        REQUIRE( callAlg( nums, 8 ) == normalized( exp ) );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{ 2 };
        const auto exp = std::vector<Vec>{};
        REQUIRE( callAlg( nums , 1 ) == normalized( exp ) );
    }
}

} // namespace {
} // namespace lc::t39

