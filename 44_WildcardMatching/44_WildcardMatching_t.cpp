#include <catch_test_macros.hpp>
#include "44_WildcardMatching.h"
#include "44_WildcardMatching_V2.h"

namespace lc::t44 {
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
TEST_CASE( "44_WildcardMatching example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto s = std::string{ "aa" };
        const auto p = std::string{ "a" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "example 2" ) {
        const auto s = std::string{ "aa" };
        const auto p = std::string{ "*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "example 3" ) {
        const auto s = std::string{ "cb" };
        const auto p = std::string{ "?a" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "example 4" ) {
        const auto s = std::string{ "adceb" };
        const auto p = std::string{ "*a*b" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "example 5" ) {
        const auto s = std::string{ "acdcb" };
        const auto p = std::string{ "a*c?b" };
        REQUIRE( callAlg( s, p ) == false );
    }
}

//------------------------------
TEST_CASE( "44_WildcardMatching my testcases", "[]" ) {
    SECTION( "both empty" ) {
        const auto s = std::string{};
        const auto p = std::string{};
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "empty string and star pattern" ) {
        const auto s = std::string{};
        const auto p = std::string{ "*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "long string and star pattern" ) {
        const auto s = std::string{ "asasas" };
        const auto p = std::string{ "**" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "empty pattern none empty string" ) {
        const auto s = std::string{ "cb" };
        const auto p = std::string{ "" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "question marks" ) {
        const auto s = std::string{ "cb" };
        const auto p = std::string{ "??" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "question mark and empty string" ) {
        const auto s = std::string{ "" };
        const auto p = std::string{ "?" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "none trivial case" ) {
        const auto s = std::string{ "sdsdssdsdd" };
        const auto p = std::string{ "**sd??dsd**" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 1" ) {
        const auto s = std::string{ "absde" };
        const auto p = std::string{ "ab*de" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 2" ) {
        const auto s = std::string{ "ab*b" };
        const auto p = std::string{ "abcd" };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "pattern start with star " ) {
        const auto s = std::string{
            "abbabaaabbac"
        };
        const auto p = std::string{
            "**aa*****ba*"
        };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 3" ) {
        const auto s = std::string{
            "abbabaaabbaabbaaabbba"
        };
        const auto p = std::string{
            "**aa*****ba*a*bb**aa*ab*bb"
        };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "just case 4" ) {
        const auto s = std::string{
            "abbabaaabbaabbaaabbb"
        };
        const auto p = std::string{
            "**aa*****ba*a?*bb**aa*ab*bb"
        };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "just case 5" ) {
        const auto s = std::string{
            "aaabbaab"
        };
        const auto p = std::string{
            "*aa*ba*a?*b"
        };
        REQUIRE( callAlg( s, p ) == false );
    }

    SECTION( "just case 6" ) {
        const auto s = std::string{ "adceb" };
        const auto p = std::string{ "*a*" };
        REQUIRE( callAlg( s, p ) == true );
    }

    SECTION( "just case 7" ) {
        const auto s = std::string{ "a" };
        const auto p = std::string{ "a*" };
        REQUIRE( callAlg( s, p ) == true );
    }
}

//------------------------------
TEST_CASE( "44_WildcardMatching exponential O(.) test", "[]" ) {
    SECTION( "enormous test1" ) {
        const auto s = std::string{
            "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
        };
        const auto p = std::string{
            "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
        };
        REQUIRE( callAlg( s, p ) == false );
    }
}

} // namespace {
} // namespace lc::t44

