#include <catch_all.hpp>
#include "50_PowXN.h"

namespace lc::t50 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( double x, int n ) noexcept -> double {
    return Solution::myPow( x, n );
}

//------------------------------
TEST_CASE( "50_PowXN example testcases", "[]" ) {
    SECTION( "example 1" ) {
        REQUIRE( callAlg( 2.00000, 10 ) == 1024. );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( 2.10000, 3 ) == Catch::Approx(9.26100) );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( 2.00000, -2 ) == 0.25 );
    }
}

//------------------------------
TEST_CASE( "50_PowXN my testcases", "[]" ) {
    SECTION( "negative x" ) {
        REQUIRE( callAlg( -2.00000, 10 ) == 1024. );
        REQUIRE( callAlg( -2.00000, 9 ) == -512. );
    }

    SECTION( "corner cases" ) {
        REQUIRE( callAlg( 1., 3 ) == 1. );
        REQUIRE( callAlg( -1., 3 ) == -1. );
        REQUIRE( callAlg( -1., 4 ) == 1. );
        REQUIRE( callAlg( -1., 0 ) == 1. );
        REQUIRE( callAlg( 1., 0 ) == 1. );
        REQUIRE( callAlg( 4., 1 ) == 4. );
        REQUIRE( callAlg( -3., 1 ) == -3. );
        REQUIRE( callAlg( 0., 5 ) == 0. );
    }

    SECTION( "int overflow" ) {
        using nl = std::numeric_limits<int>;
        REQUIRE( callAlg( 0.00001, nl::max()-1 ) == 0. );
        REQUIRE( callAlg( 1.00001, nl::lowest()+1 ) == 0. );
        REQUIRE( callAlg( 0.00001, nl::max() ) == 0. );
        REQUIRE( callAlg( 1.00001, nl::lowest() ) == 0. );
    }
}

} // namespace {
} // namespace lc::t50

