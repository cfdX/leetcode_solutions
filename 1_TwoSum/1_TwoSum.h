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
    auto twoSum( std::vector<int> const& nums, int target ) -> std::vector<int> {
        return twoSum2( nums, target );
    }

    //------------------------------
    // O(n) + hash_table
    static
    auto twoSum1( std::vector<int> const& nums, int target ) -> std::vector<int>;

    //------------------------------
    // O(n logn)
    static
    auto twoSum2( std::vector<int> const& nums, int target ) -> std::vector<int>;

    //------------------------------
    // O(n logn) (no binary search)
    // второй этапе тут будет делаться за линейное время, а не O(n logn)
    static
    auto twoSum3( std::vector<int> const& nums, int target ) -> std::vector<int>;
};

} // namespace lc::t1
