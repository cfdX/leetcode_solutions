#include "47_PermutationsII.h"

#include <algorithm>
#include "../46_Permutations/46_Permutations.h"

namespace lc::t47 {

//------------------------------
[[nodiscard]]
auto Solution::permuteUnique(
            std::vector<int> nums )
        -> std::vector<std::vector<int>> {
    // нам подходит процедура из 46 задачи, она уже делает что нужно
    using task46 = t46::Solution;
    if ( true == nums.empty() ) {
        return {};
    }
    auto perm_cnt = task46::fact( nums.size() );
    {
        std::sort( nums.begin(), nums.end() );
        auto repeat_cnt = std::size_t{1};
        for ( std::size_t i = 1; i < nums.size(); ++i ) {
            if ( nums[ i - 1 ] != nums[ i ] ) {
                perm_cnt /= task46::fact( repeat_cnt );
                repeat_cnt = 1;
            } else {
                ++repeat_cnt;
            }
        }
        perm_cnt /= task46::fact( repeat_cnt );
    }
    auto res = std::vector<std::vector<int>>{
        std::move(nums)
    };
    for ( std::size_t i = 1; i < perm_cnt; ++i ) {
        res.push_back( task46::nextPermutation( res.back() ) );
    }
    return res;
}

} // namespace lc::t47
