#include <catch_test_macros.hpp>
#include "30_SubstringWithConcatenationOfAllWords.h"

#include <algorithm>

namespace lc::t30 {
namespace {

//------------------------------
using namespace std::string_view_literals;

//------------------------------
using Indexes = std::vector<int>;
using Strings = std::vector<std::string>;

//------------------------------
[[nodiscard]]
auto callAlg( std::string_view s, Strings const& words ) -> Indexes {
    auto res = Solution::findSubstring( s, words );
    // сортируем выхлоп для удобства сравнения
    std::sort( res.begin(), res.end() );
    return res;
}

//------------------------------
TEST_CASE( "30_SubstringWithConcatenationOfAllWords example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto s = "barfoothefoobarman"sv;
        const auto w = Strings{ "foo", "bar" };
        REQUIRE( callAlg( s, w ) == Indexes{ 0, 9 } );
    }

    SECTION( "example 2" ) {
        const auto s = "wordgoodgoodgoodbestword"sv;
        const auto w = Strings{ "word", "good", "best", "word" };
        REQUIRE( callAlg( s, w ) == Indexes{} );
    }

    SECTION( "example 3" ) {
        const auto s = "barfoofoobarthefoobarman"sv;
        const auto w = Strings{ "bar", "foo", "the" };
        REQUIRE( callAlg( s, w ) == Indexes{ 6, 9, 12 } );
    }
}

//------------------------------
TEST_CASE( "30_SubstringWithConcatenationOfAllWords my testcases", "[]" ) {
    SECTION( "empty str" ) {
        const auto s = ""sv;
        const auto w = Strings{ "foo", "bar" };
        REQUIRE( callAlg( s, w ) == Indexes{} );
    }

    SECTION( "empty array" ) {
        const auto s = "aaa"sv;
        const auto w = Strings{};
        REQUIRE( callAlg( s, w ) == Indexes{0,1,2} );
    }

    SECTION( "example 2" ) {
        const auto s = "wordgoodgoodgoodbestword"sv;
        const auto w = Strings{ "word", "good", "best", "word" };
        REQUIRE( callAlg( s, w ) == Indexes{} );
    }

    SECTION( "example 3 with shift 1" ) {
        const auto s = "xbarfoofoobarthefoobarman"sv;
        const auto w = Strings{ "bar", "foo", "the" };
        REQUIRE( callAlg( s, w ) == Indexes{ 7, 10, 13 } );
    }

    SECTION( "example 3 with shift 2" ) {
        const auto s = "xybarfoofoobarthefoobarman"sv;
        const auto w = Strings{ "bar", "foo", "the" };
        REQUIRE( callAlg( s, w ) == Indexes{ 8, 11, 14 } );
    }

    SECTION( "whole string" ) {
        const auto s = "goodgoodbestword"sv;
        const auto w = Strings{ "word", "good", "best", "good" };
        REQUIRE( callAlg( s, w ) == Indexes{ 0 } );
    }

    SECTION( "at the end" ) {
        const auto s = "wordgoodgoodgoodbestword"sv;
        const auto w = Strings{ "word", "good", "best", "good" };
        REQUIRE( callAlg( s, w ) == Indexes{ 8 } );
    }

    SECTION( "at the end (shifted start)" ) {
        const auto s = "awordgoodgoodgoodbestword"sv;
        const auto w = Strings{ "word", "good", "best", "good" };
        REQUIRE( callAlg( s, w ) == Indexes{ 9 } );
    }
}

} // namespace {
} // namespace lc::t30

