#include "31_NextPermutation.h"

#include <algorithm>

namespace lc::t31 {

//------------------------------
void Solution::nextPermutation( std::vector<int>& nums ) noexcept {
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
            return;
        }
    }
    std::reverse( nums.begin(), nums.end() );
}

} // namespace lc::t31
