#include <catch_all.hpp>
#include "47_PermutationsII.h"

namespace lc::t47 {
namespace {

using ResVec = std::vector<std::vector<int>>;

//------------------------------
[[nodiscard]]
auto callAlg( std::vector<int> const& nums ) -> ResVec {
    return Solution::permuteUnique( nums );
}

//------------------------------
TEST_CASE( "47_PermutationsII example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto exp = ResVec{
              { 1, 1, 2 }
            , { 1, 2, 1 }
            , { 2, 1, 1 }
        };
        REQUIRE( callAlg( { 1, 1, 2 } ) == exp );
    }

    SECTION( "example 2" ) {
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
}


//------------------------------
TEST_CASE( "47_PermutationsII my testcases", "[]" ) {
    SECTION( "example 1 but not sorted" ) {
        const auto exp = ResVec{
              { 1, 1, 2 }
            , { 1, 2, 1 }
            , { 2, 1, 1 }
        };
        REQUIRE( callAlg( { 2, 1, 1 } ) == exp );
    }

    SECTION( "empty input" ) {
        REQUIRE( callAlg( {} ) == ResVec{} );
    }

    SECTION( "non trivial" ) {
        const auto exp = ResVec{
              { 1, 1, 2, 3, 3 }
            , { 1, 1, 3, 2, 3 }
            , { 1, 1, 3, 3, 2 }
            , { 1, 2, 1, 3, 3 }
            , { 1, 2, 3, 1, 3 }
            , { 1, 2, 3, 3, 1 }
            , { 1, 3, 1, 2, 3 }
            , { 1, 3, 1, 3, 2 }
            , { 1, 3, 2, 1, 3 }
            , { 1, 3, 2, 3, 1 }
            , { 1, 3, 3, 1, 2 }
            , { 1, 3, 3, 2, 1 }
            , { 2, 1, 1, 3, 3 }
            , { 2, 1, 3, 1, 3 }
            , { 2, 1, 3, 3, 1 }
            , { 2, 3, 1, 1, 3 }
            , { 2, 3, 1, 3, 1 }
            , { 2, 3, 3, 1, 1 }
            , { 3, 1, 1, 2, 3 }
            , { 3, 1, 1, 3, 2 }
            , { 3, 1, 2, 1, 3 }
            , { 3, 1, 2, 3, 1 }
            , { 3, 1, 3, 1, 2 }
            , { 3, 1, 3, 2, 1 }
            , { 3, 2, 1, 1, 3 }
            , { 3, 2, 1, 3, 1 }
            , { 3, 2, 3, 1, 1 }
            , { 3, 3, 1, 1, 2 }
            , { 3, 3, 1, 2, 1 }
            , { 3, 3, 2, 1, 1 }
        };
        REQUIRE( callAlg( { 1, 2, 3, 3, 1 } ) == exp );
    }

    SECTION( "three repetetion" ) {
        const auto exp = ResVec{
              { 1, 1, 1, 2 }
            , { 1, 1, 2, 1 }
            , { 1, 2, 1, 1 }
            , { 2, 1, 1, 1 }
        };
        REQUIRE( callAlg( { 2, 1, 1, 1 } ) == exp );
    }
}

} // namespace {
} // namespace lc::t47

