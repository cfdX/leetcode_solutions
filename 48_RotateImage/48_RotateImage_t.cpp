#include <catch_all.hpp>
#include "48_RotateImage.h"

namespace lc::t48 {
namespace {

using Matr = std::vector<std::vector<int>>;

//------------------------------
[[nodiscard]]
auto callAlg( Matr const& matr ) -> Matr {
    auto copy_matr = matr;
    Solution::rotate( copy_matr );
    return copy_matr;
}

//------------------------------
TEST_CASE( "48_RotateImage example testcases", "[]" ) {
    SECTION( "example 1" ) {
        const auto input = Matr{
              { 1, 2, 3 }
            , { 4, 5, 6 }
            , { 7, 8, 9 }
        };
        const auto exp = Matr{
              { 7, 4, 1 }
            , { 8, 5, 2 }
            , { 9, 6, 3 }
        };
        REQUIRE( callAlg( input ) == exp );
    }

    SECTION( "example 2" ) {
        const auto input = Matr{
              {  5,  1,  9, 11 }
            , {  2,  4,  8, 10 }
            , { 13,  3,  6,  7 }
            , { 15, 14, 12, 16 }
        };
        const auto exp = Matr{
              { 15, 13,  2,  5 }
            , { 14,  3,  4,  1 }
            , { 12,  6,  8,  9 }
            , { 16,  7, 10, 11 }
        };
        REQUIRE( callAlg( input ) == exp );
    }

    SECTION( "example 3" ) {
        const auto input = Matr{ {1} };;
        REQUIRE( callAlg( input ) == input );
    }

    SECTION( "example 2" ) {
        const auto input = Matr{
              { 1, 2 }
            , { 3, 4 }
        };
        const auto exp = Matr{
              { 3, 1 }
            , { 4, 2 }
        };
        REQUIRE( callAlg( input ) == exp );
    }
}

} // namespace {
} // namespace lc::t48

