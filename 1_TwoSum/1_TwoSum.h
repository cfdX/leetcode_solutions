#include <vector>

namespace lc::t1 {

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    static
    auto twoSum( std::vector<int>& nums, int target) -> std::vector<int>;
};

} // namespace lc::t1
