#include <catch_all.hpp>
#include "31_NextPermutation.h"

namespace lc::t31 {
namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto callAlg( Vec nums ) -> Vec {
    Solution::nextPermutation( nums );
    return nums;
}

//------------------------------
TEST_CASE( "31_NextPermutation example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( { 1, 2, 3 } ) == Vec{ 1, 3, 2 } );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( { 3, 2, 1 } ) == Vec{ 1, 2, 3 } );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( { 1, 1, 5 } ) == Vec{ 1, 5, 1 } );
    }

    SECTION( "example 4" ) {
        REQUIRE( callAlg( { 1 } ) == Vec{ 1 } );
    }
}

} // namespace {
} // namespace lc::t31

