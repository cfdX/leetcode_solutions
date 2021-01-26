#ifndef LC_34_FIRSTANDLASTPOSITIONOFELEMINSORTEDARR_H
#define LC_34_FIRSTANDLASTPOSITIONOFELEMINSORTEDARR_H

#include <vector>

namespace lc::t34 {

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto searchRange(
                  std::vector<int> const& nums
                , int target ) noexcept
            -> std::vector<int>;
};

} // namespace lc::t34

#endif // LC_34_FIRSTANDLASTPOSITIONOFELEMINSORTEDARR_H
