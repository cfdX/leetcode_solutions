#include <catch_test_macros.hpp>
#include "15_3Sum.h"

#include "../TestUtils.h"

namespace lc::t15 {
namespace {

using Vec = std::vector<int>;
using Result = std::vector<Vec>;

//------------------------------
[[nodiscard]]
auto normalized( std::vector<Vec> res ) -> std::vector<Vec> {
    return sortVectorAndSubVectors( std::move( res ) );
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
