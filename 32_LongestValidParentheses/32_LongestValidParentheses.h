#ifndef LC_32_LONGESTVALIDPARENTHESES_H
#define LC_32_LONGESTVALIDPARENTHESES_H

#include <string>

namespace lc::t32 {

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n)
    [[nodiscard]]
    static
    auto longestValidParentheses(
                std::string const& s ) noexcept
            -> int;
};

} // namespace lc::t32

#endif // LC_32_LONGESTVALIDPARENTHESES_H
