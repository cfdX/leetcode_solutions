#ifndef LC_11_CONTAINERWITHMOSTWATER_H
#define LC_11_CONTAINERWITHMOSTWATER_H

#include <vector>

namespace lc::t11 {

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n) time, O(1) space
    [[nodiscard]]
    static
    auto maxArea( std::vector<int> const& height ) noexcept -> int;
};

} // namespace lc::t11

#endif // LC_11_CONTAINERWITHMOSTWATER_H
