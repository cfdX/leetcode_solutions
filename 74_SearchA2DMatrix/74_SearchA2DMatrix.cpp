#include "74_SearchA2DMatrix.h"

#include <algorithm>

namespace lc::t74 {

//------------------------------
[[nodiscard]]
auto Solution::searchMatrix(
              std::vector<std::vector<int>> const& matrix
            , int target ) noexcept
        -> bool {
    if ( true == matrix.empty() ) {
        return false;
    }
    const auto checkRow = [target]( const auto& row ) {
        return std::binary_search(
            row->begin(), row->end(), target
        );
    };
    const auto row = std::lower_bound(
          matrix.begin()
        , matrix.end()
        , target
        , []( const auto& o1, const auto& o2 ) {
            return o1.front() < o2;//.front();
        }
    );
    if ( row == matrix.begin() ) {
        return checkRow( row );
    }
    if ( row != matrix.end() ) {
        if ( row->front() == target ) {
            return true;
        }
    }
    return checkRow( row - 1 );
}

} // namespace lc::t74

