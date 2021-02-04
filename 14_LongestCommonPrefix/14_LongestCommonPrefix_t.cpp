#include <catch_test_macros.hpp>
#include "14_LongestCommonPrefix.h"

namespace lc::t14 {
namespace {

using Strings = std::vector<std::string>;

//------------------------------
[[nodiscard]]
auto callAlg( Strings const& strs ) -> std::string {
    return Solution::longestCommonPrefix( strs );
}

//------------------------------
TEST_CASE( "14_LongestCommonPrefix example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto strs = Strings{
            "flower", "flow", "flight"
        };
        REQUIRE( callAlg( strs ) == "fl" );
    }

    SECTION( "example 2" ) {
        const auto strs = Strings{
            "dog", "racecar", "car"
        };
        REQUIRE( callAlg( strs ) == "" );
    }
}

} // namespace {
} // namespace lc::t14
