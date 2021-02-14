#include "33_SearchInRotatedSortedArray.h"

namespace lc::t33 {

namespace {

//------------------------------
[[nodiscard]]
auto searchRotateCentre( std::vector<int> const& nums ) noexcept -> std::size_t {
    if ( nums.front() < nums.back() ) {
        return nums.size();
    }
    auto b = std::size_t{0};
    auto e = nums.size() - 1;
    while ( (b+1) != e ) {
        const auto new_ind = b + ( e - b ) / 2;
        if ( nums[b] < nums[new_ind] ) {
            b = new_ind;
        } else {
            e = new_ind;
        }
    }
    return e;
}

//------------------------------
template<class Iter>
[[nodiscard]]
auto searchInRange( Iter b, Iter e, int target ) noexcept -> int {
    const auto iter = std::lower_bound(
        b, e, target
    );
    if ( iter == e ) {
        return -1;
    }
    if ( *iter == target ) {
        return static_cast<int>( std::distance( b, iter ) );
    }
    return -1;
}
} // namespace {


//------------------------------
[[nodiscard]]
auto Solution::search(
              std::vector<int> const& nums
            , int target ) noexcept
        -> int {
    if ( true == nums.empty() ) {
        return -1;
    }
    if ( 1 == nums.size() ) {
        return ( target == nums.front() ) ? 0 : -1;
    }
    const auto rot_center = searchRotateCentre( nums );
    if ( target < nums.front() ) {
        const auto res = searchInRange(
              nums.begin() + rot_center
            , nums.end()
            , target
        );
        if ( res == -1 ) {
            return -1;
        }
        return res + static_cast<int>( rot_center );
    }
    return searchInRange(
          nums.begin()
        , nums.begin() + rot_center
        , target
    );
}

} // namespace lc::t33
