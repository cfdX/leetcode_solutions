#include <catch_test_macros.hpp>
#include "TestUtils.h"

namespace lc {
namespace {

//------------------------------
TEST_CASE( "TestUtils sortVectorAndSubVectors", "[]" ) {
    using Vec = std::vector<std::vector<int>>;
    SECTION( "case 1" ) {
        auto in = Vec{
              { 3, 2, 1 }
            , { 1, 0 }
            , { 2, -1, 7 }
        };
        const auto out = Vec{
              { -1, 2, 7 }
            , { 0, 1 }
            , { 1, 2, 3 }
        };
        REQUIRE( sortVectorAndSubVectors( std::move(in) ) == out );
    }
}

} // namespace {
} // namespace lc

