#ifndef LC_45_JUMPGAMEII_H
#define LC_45_JUMPGAMEII_H

#include <vector>

namespace lc::t45 {

/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n) solution
    [[nodiscard]]
    static
    auto jump( std::vector<int>& nums ) noexcept -> int;
};

} // namespace lc::t45

#endif // LC_31_NEXTPERMUTATION_H
