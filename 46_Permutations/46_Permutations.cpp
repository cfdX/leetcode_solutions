#include "46_Permutations.h"

#include <algorithm>
#include "../31_NextPermutation/31_NextPermutation.h"

namespace lc::t46 {

//------------------------------
[[nodiscard]]
auto Solution::nextPermutation( Vec nums ) -> Vec {
    // подходит процедура из той задачи
    // но мы хотим копию, так основной цикл симпатичнее
    t31::Solution::nextPermutation( nums );
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
