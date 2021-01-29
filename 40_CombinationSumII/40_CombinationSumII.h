#ifndef LC_40_COMBINATIONSUMII_H
#define LC_40_COMBINATIONSUMII_H

#include <vector>

namespace lc::t40 {

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto combinationSum2(
                  std::vector<int>& candidates
                , int target )
            -> std::vector<std::vector<int>>;
};

} // namespace lc::t40

#endif // LC_40_COMBINATIONSUMII_H
