#include <catch_test_macros.hpp>
#include "10_RegularExpressionMatching.h"

namespace lc::t10 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& s, std::string const& p ) -> bool {
    return Solution::isMatch( s, p );
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

} // namespace {
} // namespace lc::t10

