#ifndef LC_7_REVERSEINTEGER_H
#define LC_7_REVERSEINTEGER_H

namespace lc::t7 {

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto reverse( int x ) noexcept -> int;
};

} // namespace lc::t7

#endif // LC_7_REVERSEINTEGER_H
