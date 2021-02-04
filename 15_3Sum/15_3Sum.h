#ifndef LC_15_3SUM_H
#define LC_15_3SUM_H

#include <vector>

namespace lc::t15 {

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto threeSum( std::vector<int>& nums ) -> std::vector<std::vector<int>>;
};

} // namespace lc::t15

#endif // LC_15_3SUM_H
