#ifndef LC_46_PERMUTATIONS_H
#define LC_46_PERMUTATIONS_H

#include <vector>

namespace lc::t46 {

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto permute(
                std::vector<int> nums)
            -> std::vector<std::vector<int>>;
};

} // namespace lc::t46

#endif // LC_46_PERMUTATIONS_H
