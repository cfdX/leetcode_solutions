#include <catch_all.hpp>
#include "32_LongestValidParentheses.h"

namespace lc::t32 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string s ) -> int {
    // для увеличения числа проверок смотрим и на развернутую строку
    const auto direct_res = Solution::longestValidParentheses( s );
    // разворот строки
    std::reverse( s.begin(), s.end() );
    std::transform( s.begin(), s.end(), s.begin(), []( auto c ) {
        return c == ')' ? '(' : ')';
    } );
    const auto reverse_res = Solution::longestValidParentheses( s );
    REQUIRE( reverse_res == direct_res );
    return direct_res;
};

//------------------------------
TEST_CASE( "32_LongestValidParentheses example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( "(()" ) == 2 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( ")()())" ) == 4 );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( "" ) == 0 );
    }
}

//------------------------------
TEST_CASE( "32_LongestValidParentheses my testcases", "[]" ) {
    REQUIRE( callAlg( "(((((()" ) == 2 );
    REQUIRE( callAlg( "(((((()(" ) == 2 );
    REQUIRE( callAlg( "(((((()(())(" ) == 6 );
}

} // namespace {
} // namespace lc::t32
