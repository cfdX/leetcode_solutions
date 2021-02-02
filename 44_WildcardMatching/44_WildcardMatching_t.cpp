#include <catch_all.hpp>
#include "44_WildcardMatching.h"

namespace lc::t44 {
namespace {

//------------------------------
[[nodiscard]]
auto callAlg( std::string const& s, std::string const& p ) noexcept -> bool {
    return Solution::isMatch( s, p );
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

    SECTION( "exponential O(.) test" ) {
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
