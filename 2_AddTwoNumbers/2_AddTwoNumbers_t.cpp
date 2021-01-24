#include <catch_all.hpp>
#include "2_AddTwoNumbers.h"

namespace lc::t2 {
namespace {

//------------------------------
using Vec = std::vector<int>;

[[nodiscard]]
auto callAlg( Vec const& n1, Vec const& n2 ) -> Vec {
    const auto l1 = generateList( n1 );
    const auto l2 = generateList( n2 );
    const auto res_l12 = ListUniquePtr{
        Solution::addTwoNumbers(
            l1.get(), l2.get()
        )
    };
    const auto res_v12 = listToVec( res_l12.get() );
    const auto res_l21 = ListUniquePtr{
        Solution::addTwoNumbers(
            l2.get(), l1.get()
        )
    };
    const auto res_v21 = listToVec( res_l21.get() );
    REQUIRE( res_v12 == res_v21 );
    return res_v12;
}

//------------------------------
TEST_CASE( "example testcases", "[2_AddTwoNumbers]" ) {
    SECTION( "example 1" ) {
        const auto n1 = Vec{ 2, 4, 3 };
        const auto n2 = Vec{ 5, 6, 4 };
        const auto exp = Vec{ 7, 0, 8 };
        REQUIRE( callAlg( n1, n2 ) == exp );
    }

    SECTION( "example 2" ) {
        const auto zero = Vec{ 0 };
        REQUIRE( callAlg( zero, zero ) == zero );
    }

    SECTION( "example 3" ) {
        const auto n1 = Vec{ 9, 9, 9, 9, 9, 9, 9 };
        const auto n2 = Vec{ 9, 9, 9, 9 };
        const auto exp = Vec{ 8, 9, 9, 9, 0, 0, 0, 1 };
        REQUIRE( callAlg( n1, n2 ) == exp );
    }
}

//------------------------------
TEST_CASE( "corner cases", "[2_AddTwoNumbers]" ) {
    SECTION( "empty lists" ) {
        REQUIRE( callAlg( {}, {} ) == Vec{} );
    }

    SECTION( "one empty list" ) {
        REQUIRE( callAlg( {}, {} ) == Vec{} );
    }
}

} // namespace {
} // namespace lc::t2

