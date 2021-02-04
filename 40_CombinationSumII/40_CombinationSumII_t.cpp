#include <catch_test_macros.hpp>
#include "40_CombinationSumII.h"

#include "../TestUtils.h"

namespace lc::t40 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto normalized( std::vector<Vec> res ) -> std::vector<Vec> {
    return sortVectorAndSubVectors( std::move( res ) );
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

