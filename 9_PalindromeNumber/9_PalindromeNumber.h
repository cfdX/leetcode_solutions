#ifndef LC_9_PALINDROMENUMBER_H
#define LC_9_PALINDROMENUMBER_H

namespace lc::t9 {

/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto isPalindrome( int x ) noexcept -> bool;
};

} // namespace lc::t9

#endif // LC_9_PALINDROMENUMBER_H
