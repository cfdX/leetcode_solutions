#include <catch_all.hpp>
#include "6_ZigZagConversion.h"

namespace lc::t6 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string str, int rows ) -> std::string {
    return Solution::convert( str, rows );
}

//------------------------------
TEST_CASE( "6_ZigZagConversion example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( "PAYPALISHIRING", 3 ) == "PAHNAPLSIIGYIR" );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( "PAYPALISHIRING", 4 ) == "PINALSIGYAHRPI" );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( "A", 1 ) == "A" );
    }
}

} // namespace {
} // namespace lc::t6

