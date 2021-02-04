#include <catch_test_macros.hpp>
#include "39_CombinationSum.h"

#include "../TestUtils.h"


namespace lc::t39 {
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

