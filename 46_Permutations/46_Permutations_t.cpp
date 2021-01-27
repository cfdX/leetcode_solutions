#include <catch_all.hpp>
#include "46_Permutations.h"

namespace lc::t46 {
namespace {

using ResVec = std::vector<std::vector<int>>;

//------------------------------
[[nodiscard]]
auto callAlg( std::vector<int> const& nums ) -> ResVec {
    return Solution::permute( nums );
}

//------------------------------
TEST_CASE( "46_Permutations example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto exp = ResVec{
              { 1, 2, 3 }
            , { 1, 3, 2 }
            , { 2, 1, 3 }
            , { 2, 3, 1 }
            , { 3, 1, 2 }
            , { 3, 2, 1 }
        };
        REQUIRE( callAlg( { 1, 2, 3 } ) == exp );
    }

    SECTION( "example 2" ) {
        const auto exp = ResVec{
              { 0, 1 }
            , { 1, 0 }
        };
        REQUIRE( callAlg( { 0, 1 } ) == exp );
    }

    SECTION( "example 3" ) {
        const auto exp = ResVec{ { 1 } };
        REQUIRE( callAlg( { 1 } ) == exp );
    }
}


//------------------------------
TEST_CASE( "46_Permutations my testcases", "[]" ) {
    SECTION( "example 1 but not sorted" ) {
        const auto exp = ResVec{
              { 2, 3, 1 }
            , { 3, 1, 2 }
            , { 3, 2, 1 }
            , { 1, 2, 3 }
            , { 1, 3, 2 }
            , { 2, 1, 3 }
        };
        REQUIRE( callAlg( { 2, 3, 1 } ) == exp );
    }

    SECTION( "empty input" ) {
        REQUIRE( callAlg( {} ) == ResVec{} );
    }
}

} // namespace {
} // namespace lc::t46

