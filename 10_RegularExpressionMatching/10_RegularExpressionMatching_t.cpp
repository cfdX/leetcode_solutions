#include <catch_test_macros.hpp>
#include "10_RegularExpressionMatching.h"
#include "10_RegularExpressionMatching_V2.h"

namespace lc::t10 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& s, std::string const& p ) -> bool {
    const auto v1 = Solution::isMatch( s, p );
    const auto v2 = Solution_V2::isMatch( s, p );
    REQUIRE( v1 == v2 );
    return v2;
}

//------------------------------
TEST_CASE( "10_RegularExpressionMatching example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto s = std::string{ "aa" };
        const auto p = std::string{ "a" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "example 2" ) {
        const auto s = std::string{ "aa" };
        const auto p = std::string{ "a*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "example 3" ) {
        const auto s = std::string{ "ab" };
        const auto p = std::string{ ".*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "example 4" ) {
        const auto s = std::string{ "aab" };
        const auto p = std::string{ "c*a*b" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "example 5" ) {
        const auto s = std::string{ "mississippi" };
        const auto p = std::string{ "mis*is*p*." };
        REQUIRE( callAlg( s, p ) == false );
    }
}

//------------------------------
TEST_CASE( "10_RegularExpressionMatching my testcases", "[]" ) {
    SECTION( "just case 1" ) {
        const auto s = std::string{ "abbceda" };
        const auto p = std::string{ "abb*.*d." };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 2" ) {
        const auto s = std::string{ "abbbceda" };
        const auto p = std::string{ "abb*.*d." };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 3" ) {
        const auto s = std::string{ "abbbceda" };
        const auto p = std::string{ "abb*.d." };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "just case 4" ) {
        const auto s = std::string{ "abbbcedab" };
        const auto p = std::string{ "abb.*.d.b*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 6" ) {
        const auto s = std::string{ "mississippi" };
        const auto p = std::string{ "mis*is*ip*." };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 7" ) {
        const auto s = std::string{ "aaa" };
        const auto p = std::string{ "ab*ac*a" };
        REQUIRE( callAlg( s, p ) == true );
    }
}

} // namespace {
} // namespace lc::t10

