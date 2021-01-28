#include "42_TrappingRainWater.h"

#include <algorithm>

namespace lc::t42 {

namespace {

//------------------------------
template<class Iter>
[[nodiscard]]
auto halfTrap( Iter begin, Iter end ) noexcept -> int {
    auto sum = int{0};
    auto curr_max_height = int{0};
    for ( ; begin != end; ++begin ) {
        const auto curr_height = *begin;
        curr_max_height = std::max( curr_height, curr_max_height );
        sum += curr_max_height - curr_height;
    }
    return sum;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::trap( std::vector<int> const& height ) noexcept -> int {
    const auto max_iter = std::max_element(
        height.begin(), height.end()
    );
    if ( max_iter == height.end() ) {
        return 0;
    }
    const auto left_sum = halfTrap(
          height.begin()
        , max_iter
    );
    const auto right_sum = halfTrap(
          height.rbegin()
        , std::make_reverse_iterator( max_iter )
    );
    return left_sum + right_sum;
}

} // namespace lc::t42
