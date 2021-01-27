#ifndef LC_31_NEXTPERMUTATION_H
#define LC_31_NEXTPERMUTATION_H

#include <vector>

namespace lc::t31 {

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    static
    void nextPermutation( std::vector<int>& nums ) noexcept;
};

} // namespace lc::t31

#endif // LC_31_NEXTPERMUTATION_H
