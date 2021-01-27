#include "46_Permutations.h"

#include <algorithm>

namespace lc::t46 {

//------------------------------
[[nodiscard]]
auto Solution::nextPermutation( Vec nums ) -> Vec {
    for ( int i = static_cast<int>(nums.size())-2; i >= 0; --i ) {
        if ( nums[i] < nums[i+1] ) {
            auto j = static_cast<std::size_t>(i) + 1;
            for ( ; j < nums.size(); ++j ) {
                if ( (nums[j] <= nums[i])  ) {
                    break;
                }
            }
            std::swap( nums[i], nums[j-1] );
            std::reverse( nums.begin() + i + 1, nums.end() );
            return nums;
        }
    }
    std::reverse( nums.begin(), nums.end() );
    return nums;
}

//------------------------------
[[nodiscard]]
auto Solution::fact( std::size_t n ) noexcept -> std::size_t {
    auto res = std::size_t{1};
    for ( std::size_t i = 1; i <= n; ++i ) {
        res *= i;
    }
    return res;
}

//------------------------------
[[nodiscard]]
auto Solution::permute( Vec nums ) -> std::vector<Vec> {
    if ( true == nums.empty() ) {
        return {};
    }
    const auto perm_cnt = fact( nums.size() );
    auto res = std::vector<Vec>{ std::move(nums) };
    for ( std::size_t i = 1; i < perm_cnt; ++i ) {
        res.push_back( nextPermutation( res.back() ) );
    }
    return res;
}

} // namespace lc::t46
