#include <catch_test_macros.hpp>
#include "36_ValidSudoku.h"

namespace lc::t36 {
namespace {

using Board = std::vector<std::vector<char>>;

//------------------------------
[[nodiscard]]
auto callAlg( Board const& b ) -> bool {
    return Solution::isValidSudoku( b );
}

//------------------------------
TEST_CASE( "36_ValidSudoku example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto board = Board{
              { '5', '3', '.', '.', '7', '.', '.', '.', '.' }
            , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
            , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        REQUIRE( callAlg( board ) == true );
    }

    SECTION( "example 2" ) {
        const auto board = Board{
              { '8', '3', '.', '.', '7', '.', '.', '.', '.' }
            , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
            , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        REQUIRE( callAlg( board ) == false );
    }
}

//------------------------------
TEST_CASE( "36_ValidSudoku my testcases", "[]" ) {
    SECTION( "wrong row" ) {
        const auto board = Board{
              { '5', '3', '7', '.', '7', '.', '.', '.', '.' }
            , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
            , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        REQUIRE( callAlg( board ) == false );
    }

    SECTION( "wrong col" ) {
        const auto board = Board{
              { '5', '3', '.', '.', '7', '.', '.', '.', '.' }
            , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '8', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
            , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        REQUIRE( callAlg( board ) == false );
    }

    SECTION( "wrong box" ) {
        const auto board = Board{
              { '5', '3', '.', '.', '7', '.', '.', '.', '.' }
            , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '9', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
            , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        REQUIRE( callAlg( board ) == false );
    }
}

} // namespace {
} // namespace lc::t36

