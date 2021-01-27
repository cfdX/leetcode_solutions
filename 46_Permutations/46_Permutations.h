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
    using Vec = std::vector<int>;

    //------------------------------
    [[nodiscard]]
    static
    auto permute( Vec nums) -> std::vector<Vec>;

    //------------------------------
    [[nodiscard]]
    static
    auto nextPermutation( Vec nums ) -> Vec;

    //------------------------------
    [[nodiscard]]
    static
    auto fact( std::size_t n ) noexcept -> std::size_t;
};

} // namespace lc::t46

#endif // LC_46_PERMUTATIONS_H
