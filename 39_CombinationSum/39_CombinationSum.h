#ifndef LC_39_COMBINATIONSUM_H
#define LC_39_COMBINATIONSUM_H

#include <vector>

namespace lc::t39 {

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto combinationSum(
                  std::vector<int>& candidates
                , int target )
            -> std::vector<std::vector<int>>;
};

} // namespace lc::t39

#endif // LC_39_COMBINATIONSUM_H