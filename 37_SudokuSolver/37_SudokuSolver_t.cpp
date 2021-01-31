#include <catch_all.hpp>
#include "37_SudokuSolver.h"

#include "../36_ValidSudoku/36_ValidSudoku.h"

namespace lc::t37 {
namespace {

using Board = std::vector<std::vector<char>>;

//------------------------------
[[nodiscard]]
auto isValid( Board const& b ) noexcept -> bool {
    return t36::Solution::isValidSudoku( b );
}

//------------------------------
[[nodiscard]]
auto callAlg( Board b ) noexcept -> Board {
    Solution::solveSudoku( b );
    REQUIRE( true == isValid( b ) );
    return b;
}

//------------------------------
TEST_CASE( "37_SudokuSolver example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto input_board = Board{
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
        const auto expected_board = Board{
              { '5', '3', '4', '6', '7', '8', '9', '1', '2' }
            , { '6', '7', '2', '1', '9', '5', '3', '4', '8' }
            , { '1', '9', '8', '3', '4', '2', '5', '6', '7' }
            , { '8', '5', '9', '7', '6', '1', '4', '2', '3' }
            , { '4', '2', '6', '8', '5', '3', '7', '9', '1' }
            , { '7', '1', '3', '9', '2', '4', '8', '5', '6' }
            , { '9', '6', '1', '5', '3', '7', '2', '8', '4' }
            , { '2', '8', '7', '4', '1', '9', '6', '3', '5' }
            , { '3', '4', '5', '2', '8', '6', '1', '7', '9' }
        };
        REQUIRE( callAlg( input_board ) == expected_board );
    }
}

//------------------------------
TEST_CASE( "37_SudokuSolver my testcases", "[]" ) {
    const auto valid_board = Board{
          { '5', '3', '4', '6', '7', '8', '9', '1', '2' }
        , { '6', '7', '2', '1', '9', '5', '3', '4', '8' }
        , { '1', '9', '8', '3', '4', '2', '5', '6', '7' }
        , { '8', '5', '9', '7', '6', '1', '4', '2', '3' }
        , { '4', '2', '6', '8', '5', '3', '7', '9', '1' }
        , { '7', '1', '3', '9', '2', '4', '8', '5', '6' }
        , { '9', '6', '1', '5', '3', '7', '2', '8', '4' }
        , { '2', '8', '7', '4', '1', '9', '6', '3', '5' }
        , { '3', '4', '5', '2', '8', '6', '1', '7', '9' }
    };
    // просто исключаем какое-то количество точек
    SECTION( "cases" ) {
        auto input_board = valid_board;
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[0][0] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[2][3] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[4][1] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[6][7] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[4][6] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[8][1] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[1][7] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[2][2] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[8][3] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[4][7] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
        input_board[4][5] = '.';
        REQUIRE( callAlg( input_board ) == valid_board );
    }

    // удаляем строку, а потом еще
    SECTION( "no row" ) {
        auto input_board = valid_board;
        for ( auto& el : input_board[3]) {
            el = '.';
        }
        REQUIRE( callAlg( input_board ) == valid_board );
        for ( auto& el : input_board[7]) {
            el = '.';
        }
        REQUIRE( callAlg( input_board ) == valid_board );
    }

    // один за одной заменяем на точки всю матрицу
    SECTION( "point after point " ) {
        auto input_board = valid_board;
        for ( auto& row : input_board ) {
            for ( auto& el : row ) {
                el = '.';
                REQUIRE( isValid( callAlg( input_board ) ) == true );
            }
        }
    }
}

//------------------------------
TEST_CASE( "37_SudokuSolver my testcases (from empty board_", "[]" ) {
    const auto empty_board  = Board( 9, std::vector<char>( 9, '.' ) );
    REQUIRE( true == isValid( callAlg( empty_board ) ) );
}

} // namespace {
} // namespace lc::t37

