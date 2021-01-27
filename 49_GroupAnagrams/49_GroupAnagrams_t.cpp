#include <catch_all.hpp>
#include "49_GroupAnagrams.h"

#include <algorithm>

namespace lc::t49 {
namespace {

using Vec = std::vector<std::string>;

//------------------------------
// отсортировали порядок строк в каждом массиве
// и потом сами массивы по первой строке
// чтоб сранивать было удобно
[[nodiscard]]
auto normalized( std::vector<Vec> res ) -> std::vector<Vec> {
    for ( auto& list : res ) {
        std::sort( list.begin(), list.end() );
    }
    std::sort(
          res.begin()
        , res.end()
        , []( auto const& o1, auto const& o2 ) {
            return o1.front() < o2.front();
        }
    );
    return res;
}

//------------------------------
[[nodiscard]]
auto callAlg( Vec const& strs ) -> std::vector<Vec> {
    return normalized(
        Solution::groupAnagrams( strs )
    );
}

//------------------------------
TEST_CASE( "49_GroupAnagrams example testcases", "[ }" ) {
    SECTION( "example 1" ) {
        const auto input = Vec{
            "eat", "tea", "tan", "ate", "nat", "bat"
        };
        const auto exp = normalized( {
              { "bat" }
            , { "nat", "tan" }
            , { "ate", "eat", "tea" }
        } );
        REQUIRE( callAlg( input ) == exp );
    }

    SECTION( "example 2" ) {
        REQUIRE( callAlg( { "" } ) == normalized( {{""}} ) );
    }

    SECTION( "example 3" ) {
        REQUIRE( callAlg( { "a" } ) == normalized( {{"a"}} ) );
    }
}

} // namespace {
} // namespace lc::t49

