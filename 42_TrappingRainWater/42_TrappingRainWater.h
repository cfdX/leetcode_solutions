#ifndef LC_42_TRAPPINGRAINWATER_H
#define LC_42_TRAPPINGRAINWATER_H

#include <vector>

namespace lc::t42 {

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n) solution
    [[nodiscard]]
    static
    auto trap( std::vector<int> const& height ) noexcept -> int;
};

} // namespace lc::t42

#endif // LC_42_TRAPPINGRAINWATER_H
