#ifndef LC_47_PERMUTATIONSII_H
#define LC_47_PERMUTATIONSII_H

#include <vector>

namespace lc::t47 {

/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto permuteUnique(
                std::vector<int> nums)
            -> std::vector<std::vector<int>>;
};

} // namespace lc::t47

#endif // LC_47_PERMUTATIONSII_H
