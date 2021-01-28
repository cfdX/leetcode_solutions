#include "45_JumpGameII.h"

namespace lc::t45 {

//------------------------------
[[nodiscard]]
auto Solution::jump( std::vector<int>& nums ) noexcept -> int {
    if ( nums.size() < 2 ) {
        return 0;
    }
    auto steps_cnt = int{0};
    auto same_steps_count_ind = std::size_t{0};
    auto next_same_steps_count_ind = std::size_t{0};
    for ( std::size_t i = 0; i < nums.size() - 1; ++i ) {
        const auto curr_steps = static_cast<std::size_t>(nums[i]);
        next_same_steps_count_ind = std::max(
              next_same_steps_count_ind
            , i + curr_steps
        );
        if ( i == same_steps_count_ind ) {
            ++steps_cnt;
            same_steps_count_ind = next_same_steps_count_ind;
        }
    }
    return steps_cnt;
}

} // namespace lc::t45
