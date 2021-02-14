#ifndef LC_153_FINDMINIMUMINROTATEDSORTEDARRAY_H
#define LC_153_FINDMINIMUMINROTATEDSORTEDARRAY_H

#include <vector>

namespace lc::t153 {

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums, return the minimum element of this array.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto findMin( std::vector<int> const& nums ) noexcept -> int;
};

} // namespace lc::t153

#endif // LC_153_FINDMINIMUMINROTATEDSORTEDARRAY_H
