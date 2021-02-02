#include <catch_test_macros.hpp>
#include "41_FirstMissingPositive.h"

namespace lc::t41 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::initializer_list<int> nums_list ) noexcept -> int {
    // алгоритм хочет мутабельный вектор, поэтому мы его тут создаем
    auto nums = std::vector<int>( nums_list.begin(), nums_list.end() );
    return Solution::firstMissingPositive( nums );
}

//------------------------------
TEST_CASE( "41_FirstMissingPositive example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( { 1, 2, 0 } ) == 3 );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( { 3, 4, -1, 1 } ) == 2 );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( { 7, 8, 9, 11, 12 } ) == 1 );
    }
}

//------------------------------
TEST_CASE( "41_FirstMissingPositive my testcases", "[]" ) {
    REQUIRE( callAlg( { 3, 2, 1 } ) == 4 );
    REQUIRE( callAlg( {} ) == 1 );
    REQUIRE( callAlg( { 3, 3, 3, 1 } ) == 2 );
    REQUIRE( callAlg( { 2 } ) == 1 );
    REQUIRE( callAlg( { 1 } ) == 2 );
}

} // namespace {
} // namespace lc::t41
