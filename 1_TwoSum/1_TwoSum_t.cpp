#include <catch_all.hpp>
#include "1_TwoSum.h"

#include <algorithm>

namespace lc::t1 {
namespace {

//------------------------------
using Sol = Solution;
using Vec = std::vector<int>;

//------------------------------
enum class Alg {
      kHashTable
    , kSortAndBSearch
};

//------------------------------
// Это по факту просто вызов тестируемого алгоритма
// но с наворотами для удобства тестирования
auto sol( Alg const alg, Vec const& nums, int const target ) -> Vec {
    // так как интерфейс задачи хочет мутабельную ссылку
    auto nums_copy = nums;
    auto res = [&]{
        switch ( alg ) {
            case Alg::kHashTable: {
                return Solution::twoSum1( nums_copy, target );
            }
            case Alg::kSortAndBSearch: {
                return Solution::twoSum2( nums_copy, target );
            }
            // [[unreachable]]
        };
    }();
    // чтоб нам было проще сравнивать результаты
    std::sort( res.begin(), res.end() );
    return res;
}

//------------------------------
//------------------------------
//------------------------------
TEST_CASE( "example test case1", "[1_TwoSum (alg1)]" ) {
    const auto nums = Vec{ 2, 7, 11, 15 };
    REQUIRE( sol( Alg::kHashTable, nums, 9 ) == Vec{ 0, 1 } );
}

//------------------------------
TEST_CASE( "example test case2", "[1_TwoSum (alg1)]" ) {
    const auto nums = Vec{ 3, 2, 4 };
    REQUIRE( sol( Alg::kHashTable, nums, 6 ) == Vec{ 1, 2 } );
}

//------------------------------
TEST_CASE( "example test case3", "[1_TwoSum (alg2)]" ) {
    const auto nums = Vec{ 3, 3 };
    REQUIRE( sol( Alg::kHashTable, nums, 6 ) == Vec{ 0, 1 } );
}

//------------------------------
//------------------------------
//------------------------------
TEST_CASE( "example test case1", "[1_TwoSum (alg2)]" ) {
    const auto nums = Vec{ 2, 7, 11, 15 };
    REQUIRE( sol( Alg::kSortAndBSearch, nums, 9 ) == Vec{ 0, 1 } );
}

//------------------------------
TEST_CASE( "example test case2", "[1_TwoSum (alg2)]" ) {
    const auto nums = Vec{ 3, 2, 4 };
    REQUIRE( sol( Alg::kSortAndBSearch, nums, 6 ) == Vec{ 1, 2 } );
}

//------------------------------
TEST_CASE( "example test case3", "[1_TwoSum (alg1)]" ) {
    const auto nums = Vec{ 3, 3 };
    REQUIRE( sol( Alg::kSortAndBSearch, nums, 6 ) == Vec{ 0, 1 } );
}

} // namespace {
} // namespace lc::t1
