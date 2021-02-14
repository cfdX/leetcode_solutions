#include "153_FindMinimumInRotatedSortedArray.h"

namespace lc::t153 {

//------------------------------
[[nodiscard]]
auto Solution::findMin( std::vector<int> const& nums ) noexcept -> int {
    if ( true == nums.empty() ) {
        return 0; // TOTHINK
    }
    if ( 1 == nums.size() ) {
        return nums.front();
    }
    const auto first_el = nums.front();
    if ( first_el < nums.back() ) {
        return first_el;
    }
    auto left = std::size_t{0};
    auto right = nums.size() - 1;
    while ( (left < right) && (left < (right-1)) ) {
        const auto middle = left + (right - left) / 2;
        if ( nums[middle] <= first_el ) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return (nums[ left ] >= first_el) ? nums[ left + 1 ] : nums[ left ];
}

} // namespace lc::t153
