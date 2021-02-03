#include "11_ContainerWithMostWater.h"

namespace lc::t11 {

//------------------------------
[[nodiscard]]
auto Solution::maxArea( std::vector<int> const& height ) noexcept -> int {
    if ( height.size() < 2 ) {
        return 0;
    }
    auto first_ind = std::size_t{0};
    auto last_ind = height.size() - 1;
    auto max_volume = int{0};
    while ( first_ind < last_ind ) {
        const auto curr_dist = static_cast<int>(last_ind - first_ind);
        const auto curr_rect_height = std::min( height[first_ind], height[last_ind] );
        const auto curr_volume = curr_rect_height * curr_dist;
        max_volume = std::max( max_volume, curr_volume );
        if ( height[ first_ind ] < height[ last_ind ] ) {
            ++first_ind;
        } else {
            --last_ind;
        }
    }
    return max_volume;
}

} // namespace lc::t11
