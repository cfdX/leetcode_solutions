#include <catch_test_macros.hpp>
#include "15_3Sum.h"

#include <algorithm>

namespace lc::t15 {
namespace {

using Vec = std::vector<int>;
using Result = std::vector<Vec>;

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
auto callAlg( Vec nums ) -> Result {
    return normalized( Solution::threeSum( nums ) );
}

//------------------------------
TEST_CASE( "15_3Sum example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto nums = Vec{
            -1, 0, 1, 2, -1, -4
        };
        const auto res = Result{
              { -1, -1, 2 }
            , { -1, 0, 1 }
        };
        REQUIRE( callAlg( nums ) == normalized( res ) );
    }

    SECTION( "example 2" ) {
        const auto nums = Vec{};
        const auto res = Result{};
        REQUIRE( callAlg( nums ) == normalized( res ) );
    }

    SECTION( "example 3" ) {
        const auto nums = Vec{ 0 };
        const auto res = Result{};
        REQUIRE( callAlg( nums ) == normalized( res ) );
    }
}

} // namespace {
} // namespace lc::t15
