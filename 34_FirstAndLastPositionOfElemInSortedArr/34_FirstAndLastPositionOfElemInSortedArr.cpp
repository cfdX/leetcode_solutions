#include "34_FirstAndLastPositionOfElemInSortedArr.h"

namespace lc::t34 {

namespace {

//------------------------------
template<bool find_first_elem>
[[nodiscard]]
auto binarySearch(
          std::vector<int> const& nums
        , int const target
        , int const range_start
        , int const range_end ) -> int {
    if ( true == nums.empty() ) {
        return -1;
    }
    auto b = range_start;
    auto e = range_end;
    while ( b < e ) {
        const auto new_ind = b + ( e - b ) / 2;
        const auto v = nums[ new_ind ];
        if ( v < target ) {
            b = new_ind + 1;
        } else if ( v > target ) {
            e = new_ind - 1;
        } else {
            if constexpr ( find_first_elem == true ) {
                if ( new_ind == 0 ) {
                    return 0;
                }
                if ( v != nums[ new_ind - 1 ] ) {
                    return new_ind;
                }
                e = new_ind - 1;
            } else {
                if ( new_ind == range_end ) {
                    return range_end;
                }
                if ( v != nums[ new_ind + 1 ] ) {
                    return new_ind;
                }
                b = new_ind + 1;
            }
        }
    }
    return (nums[b] == target) ? b : -1;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::searchRange(
              std::vector<int> const& nums
            , int target ) noexcept
        -> std::vector<int> {
    if ( true == nums.empty() ) {
        return { -1, -1 };
    }
    const auto last_arr_ind = static_cast<int>( nums.size() - 1 );
    const auto start_ind = binarySearch<true>(
          nums
        , target
        , 0
        , last_arr_ind
    );
    if ( start_ind == -1 ) {
        return { -1, -1 };
    }
    const auto end_ind = binarySearch<false>(
          nums
        , target
        , start_ind
        , last_arr_ind
    );
    return { start_ind, end_ind };
}

} // namespace lc::t34
