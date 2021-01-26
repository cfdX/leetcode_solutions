#ifndef LC_41_FIRSTMISSINGPOSITIVE_H
#define LC_41_FIRSTMISSINGPOSITIVE_H

#include <vector>

namespace lc::t41 {

/*
Given an unsorted integer array nums, find the smallest missing positive integer.

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n)
    [[nodiscard]]
    static
    auto firstMissingPositive( std::vector<int>& nums ) noexcept -> int;
};

} // namespace lc::t41

#endif // LC_41_FIRSTMISSINGPOSITIVE_H
