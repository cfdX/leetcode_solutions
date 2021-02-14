#ifndef LC_33_SEARCHINROTATEDSORTEDARRAY_H
#define LC_33_SEARCHINROTATEDSORTEDARRAY_H

#include <vector>

namespace lc::t33 {

/*
You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto search(
                  std::vector<int> const& nums
                , int target ) noexcept
            -> int;
};

} // namespace lc::t33

#endif // LC_33_SEARCHINROTATEDSORTEDARRAY_H
