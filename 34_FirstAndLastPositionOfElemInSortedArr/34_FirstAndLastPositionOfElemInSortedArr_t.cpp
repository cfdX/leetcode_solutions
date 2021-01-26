#include <catch_all.hpp>
#include "34_FirstAndLastPositionOfElemInSortedArr.h"

namespace lc::t34 {
namespace {

using Vec = std::vector<int>;

[[nodiscard]]
auto callAlg( Vec const& vec, int target ) -> Vec {
    return Solution::searchRange( vec, target );
};

//------------------------------
TEST_CASE( "34_FirstAndLastPositionOfElemInSortedArr example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 8, 10 }, 8 ) == Vec{3, 4} );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 8, 10 }, 6 ) == Vec{ -1, -1 } );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( {}, 0 ) == Vec{ -1, -1 } );
    }
}

//------------------------------
TEST_CASE( "34_FirstAndLastPositionOfElemInSortedArr my testcases", "[]" ) {
    SECTION( "many duplicates" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 8, 8, 8, 10 }, 8 ) == Vec{3, 6} );
    }

    SECTION( "only one element" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 10 }, 8 ) == Vec{3, 3} );
    }

    SECTION( "first element" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 8, 10 }, 5 ) == Vec{ 0, 0 } );
    }

    SECTION( "last element" ) {
        REQUIRE( callAlg( { 5, 7, 7, 8, 8, 10, 10 }, 10 ) == Vec{ 5, 6 } );
    }
}

} // namespace {
} // namespace lc::t34
