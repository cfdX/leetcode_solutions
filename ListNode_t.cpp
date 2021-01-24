#include <catch_all.hpp>
#include "ListNode.h"

namespace lc {
namespace {

//------------------------------
TEST_CASE( "generate", "[ListNode]" ) {
    SECTION( "empty list" ) {
        const auto list = generateList( {} );
        REQUIRE( list == nullptr );
    }

    SECTION( "one element" ) {
        const auto list = generateList( {1} );
        REQUIRE( list != nullptr );
        REQUIRE( list->val == 1 );
        REQUIRE( list->next == nullptr );
    }

    SECTION( "two elements" ) {
        const auto list = generateList( {1, 2} );
        REQUIRE( list != nullptr );
        REQUIRE( list->val == 1 );
        REQUIRE( list->next != nullptr );
        REQUIRE( list->next->val == 2 );
        REQUIRE( list->next->next == nullptr );
    }

    SECTION( "three elements" ) {
        const auto list = generateList( {1, 2, 3} );
        REQUIRE( list != nullptr );
        REQUIRE( list->val == 1 );
        const auto second = list->next;
        REQUIRE( second != nullptr );
        REQUIRE( second->val == 2 );
        const auto third = second->next;
        REQUIRE( third != nullptr );
        REQUIRE( third->val == 3 );
        REQUIRE( third->next == nullptr );
    }
}

//------------------------------
TEST_CASE( "listToVec", "[ListNode]" ) {
    using Vec = std::vector<int>;
    SECTION( "empty list" ) {
        const auto vec = listToVec( generateList( {} ).get() );
        REQUIRE( vec == Vec{} );
    }

    SECTION( "one element" ) {
        const auto vec = listToVec( generateList( {1} ).get() );
        REQUIRE( vec == Vec{1} );
    }

    SECTION( "two elements" ) {
        const auto vec = listToVec( generateList( {1, 2} ).get() );
        REQUIRE( vec == Vec{1, 2} );
    }

    SECTION( "three elements" ) {
        const auto vec = listToVec( generateList( {1, 2, 3} ).get() );
        REQUIRE( vec == Vec{1, 2, 3} );
    }
}

} // namespace {
} // namespace lc

