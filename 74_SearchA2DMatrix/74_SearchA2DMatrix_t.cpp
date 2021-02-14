#include <catch_test_macros.hpp>
#include "74_SearchA2DMatrix.h"

namespace lc::t74 {
namespace {

using Matrix = std::vector<std::vector<int>>;

//------------------------------
[[nodiscard]]
auto callAlg( Matrix const& matr, int target ) -> bool {
    return Solution::searchMatrix( matr, target );
}

//------------------------------
TEST_CASE( "74_SearchA2DMatrix example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto matr = Matrix{
              {  1,  3,  5,  7 }
            , { 10, 11, 16, 20 }
            , { 23, 30, 34, 60 }
        };
        REQUIRE( callAlg( matr, 3 ) == true );
    }

    SECTION( "example 2" ) {
        const auto matr = Matrix{
              {  1,  3,  5,  7 }
            , { 10, 11, 16, 20 }
            , { 23, 30, 34, 60 }
        };
        REQUIRE( callAlg( matr, 13 ) == false );
    }
}


//------------------------------
TEST_CASE( "74_SearchA2DMatrix my testcases", "[]" ) {
    const auto matr = Matrix{
          {  1,  3,  5,  7 }
        , { 10, 11, 16, 20 }
        , { 23, 30, 34, 60 }
    };
    REQUIRE( callAlg( matr, 1 ) == true );
    REQUIRE( callAlg( matr, 7 ) == true );
    REQUIRE( callAlg( matr, 10 ) == true );
    REQUIRE( callAlg( matr, 23 ) == true );
    REQUIRE( callAlg( matr, 20 ) == true );
    REQUIRE( callAlg( matr, 60 ) == true );
    REQUIRE( callAlg( matr, 0 ) == false );
    REQUIRE( callAlg( matr, 8 ) == false );
    REQUIRE( callAlg( matr, 4 ) == false );
    REQUIRE( callAlg( matr, 12 ) == false );
    REQUIRE( callAlg( matr, 21 ) == false );
    REQUIRE( callAlg( matr, 32 ) == false );
    REQUIRE( callAlg( matr, 65 ) == false );
}

} // namespace {
} // namespace lc::t74

