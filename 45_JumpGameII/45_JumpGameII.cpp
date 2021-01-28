#include "45_JumpGameII.h"

namespace lc::t45 {

//------------------------------
[[nodiscard]]
auto Solution::jump( std::vector<int>& nums ) noexcept -> int {
    if ( nums.size() < 1 ) {
        return 0;
    }
    constexpr const auto inf = std::numeric_limits<int>::max();
    nums.back() = 0;
    // цикл идет с конца, на самом деле, просто из-за size_t
    // его проще так написать
    for ( std::size_t i = 1; i < nums.size(); ++i ) {
        const auto ind = nums.size() - i - 1;
        const auto step = static_cast<std::size_t>( nums[ind] );
        const auto max_next_ind = std::min( step + ind, nums.size() - 1 );
        {
            const auto next = nums[ max_next_ind ];
            if ( ( step != 0 ) && ( next != inf ) ) {
                nums[ ind ] = 1 + next;
            } else {
                nums[ ind ] = inf;
            }
        }
        {
            // нужно понять, портит ли этот цикл сложность?
            auto j = ind;
            while ( ( j + 1 <= max_next_ind ) && (nums[ j ] < nums[ j + 1 ]) ) {
                nums[ j + 1 ] = nums[ j ];
                ++j;
            }
        }
    }
    return nums[0];
}

} // namespace lc::t45
