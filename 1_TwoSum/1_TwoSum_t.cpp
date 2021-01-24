#include <catch_all.hpp>
#include "1_TwoSum.h"

#include <algorithm>

namespace lc::t1 {
namespace {

//------------------------------
using Sol = Solution;
using Vec = std::vector<int>;

//------------------------------
auto call_task( Vec const& nums, int const target ) -> Vec {
    // так как интерфейс задачи хочет мутабельную ссылку
    auto nums_copy = nums;
    auto res = Solution::twoSum( nums_copy, target );
    // чтоб нам было проще сравнивать результаты
    std::sort( res.begin(), res.end() );
    return res;
}

//------------------------------
TEST_CASE( "example test case1", "[1_TwoSum]" ) {
    const auto numbers = Vec{ 2, 7, 11, 15 };
    REQUIRE( call_task( numbers, 9 ) == Vec{ 0, 1 } );
}

//------------------------------
TEST_CASE( "example test case2", "[1_TwoSum]" ) {
    const auto numbers = Vec{ 3, 2, 4 };
    REQUIRE( call_task( numbers, 6 ) == Vec{ 1, 2 } );
}

//------------------------------
TEST_CASE( "example test case3", "[1_TwoSum]" ) {
    const auto numbers = Vec{ 3, 3 };
    REQUIRE( call_task( numbers, 6 ) == Vec{ 0, 1 } );
}

} // namespace {
} // namespace lc::t1
