#include <catch_all.hpp>
#include "1_TwoSum.h"

#include <algorithm>

namespace lc::t1 {
namespace {

//------------------------------
using Sol = Solution;
using Vec = std::vector<int>;
using Alg = Vec (*)( Vec const&, int const );

//------------------------------
// Это по факту просто вызов тестируемого алгоритма
// но с наворотами для удобства тестирования
auto algAndSort( Alg const alg, Vec const& nums, int const target ) -> Vec {
    auto res = alg( nums, target );
    // чтоб нам было проще сравнивать результаты
    std::sort( res.begin(), res.end() );
    return res;
}

//------------------------------
// шаблон, чтоб работали секции (TODO это кажется хаком, нужно смотреть доки по Catch2)
template<Alg alg>
void execAllTests() {
    SECTION( "example test case1" ) {
        const auto nums = Vec{ 2, 7, 11, 15 };
        REQUIRE( algAndSort( alg, nums, 9 ) == Vec{ 0, 1 } );
    }

    SECTION( "example test case2" ) {
        const auto nums = Vec{ 3, 2, 4 };
        REQUIRE( algAndSort( alg, nums, 6 ) == Vec{ 1, 2 } );
    }

    SECTION( "example test case3" ) {
        const auto nums = Vec{ 3, 3 };
        REQUIRE( algAndSort( alg, nums, 6 ) == Vec{ 0, 1 } );
    }
}

//------------------------------
TEST_CASE( "1_TwoSum algorithm1", "[]" ) {
    execAllTests<Solution::twoSum1>();
}

//------------------------------
TEST_CASE( "1_TwoSum algorithm2", "[]" ) {
    execAllTests<Solution::twoSum2>();
}

//------------------------------
TEST_CASE( "1_TwoSum algorithm3", "[]" ) {
    execAllTests<Solution::twoSum3>();
}

} // namespace {
} // namespace lc::t1
