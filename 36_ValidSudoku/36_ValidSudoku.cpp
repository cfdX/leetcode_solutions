#include "36_ValidSudoku.h"

#include <bitset>
#include <optional>

namespace lc::t36 {

namespace {

//------------------------------
using Board = std::vector<std::vector<char>>;

//------------------------------
constexpr const auto kBoxCount = std::size_t{3};
constexpr const auto kBoardSize = kBoxCount*kBoxCount;

//------------------------------
[[nodiscard]]
auto toNum( char c ) noexcept -> std::optional<std::size_t> {
    if ( (c >= '1') && (c <= '9') ) {
        return static_cast<std::size_t>( c - '1' );
    }
    return {};
}

//------------------------------
template<class Extrator>
[[nodiscard]]
auto loop( Extrator const& extractor ) noexcept -> bool {
    auto used = std::bitset<kBoardSize>{};
    for ( std::size_t i = 0; i < kBoardSize; ++i ) {
        used.reset();
        for ( std::size_t j = 0; j < kBoardSize; ++j ) {
            const auto mb_num = toNum( extractor( i, j ) );
            if ( false == mb_num.has_value() ) {
                continue;
            }
            const auto num = *mb_num;
            if ( true == used[num] ) {
                return false;
            }
            used[num] = true;
        }
    }
    return true;
}

} // namespace

//------------------------------
[[nodiscard]]
auto Solution::isValidSudoku( Board const& board ) noexcept -> bool {

    // rows
    const auto by_row = [&]( auto i, auto j ) {
        return board[ i ][ j ];
    };
    if ( false == loop( by_row ) ) {
        return false;
    }

    // cols
    const auto by_col = [&]( auto i, auto j ) {
        return board[ j ][ i ];
    };
    if ( false == loop( by_col ) ) {
        return false;
    }

    // boxes
    const auto by_box = [&]( auto i, auto j ) {
        const auto box_row = i/kBoxCount;
        const auto box_col = i%kBoxCount;
        const auto row = box_row*kBoxCount + j/kBoxCount;
        const auto col = box_col*kBoxCount + j%kBoxCount;
        return board[ row ][ col ];
    };
    if ( false == loop( by_box ) ) {
        return false;
    }

    return true;
}

} // namespace lc::t36


