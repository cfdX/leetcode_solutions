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
// шаблон, чтоб работали секции (TODO это кажется хаком, нужно смотреть доки по Catch2)
template<Alg alg>
void exec_all_tests() {
    SECTION( "example test case1" ) {
        const auto nums = Vec{ 2, 7, 11, 15 };
        REQUIRE( sol( alg, nums, 9 ) == Vec{ 0, 1 } );
    }

    SECTION( "example test case2" ) {
        const auto nums = Vec{ 3, 2, 4 };
        REQUIRE( sol( alg, nums, 6 ) == Vec{ 1, 2 } );
    }

    SECTION( "example test case3" ) {
        const auto nums = Vec{ 3, 3 };
        REQUIRE( sol( alg, nums, 6 ) == Vec{ 0, 1 } );
    }
}

//------------------------------
TEST_CASE( "algorithm1", "[1_TwoSum]" ) {
    exec_all_tests<Alg::kHashTable>();
}

//------------------------------
TEST_CASE( "algorithm2", "[1_TwoSum]" ) {
    exec_all_tests<Alg::kSortAndBSearch>();
}

} // namespace {
} // namespace lc::t1
