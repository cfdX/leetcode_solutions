#ifndef LC_5_LONGESTPALINDROMICSUBSTRING_H
#define LC_5_LONGESTPALINDROMICSUBSTRING_H

#include <string>

namespace lc::t5 {

/*
Given a string s, return the longest palindromic substring in s.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // Решение за O(n^2)
    // TODO есть стойкое ощущение, что можно решить за O(n) - подумать
    [[nodiscard]]
    static
    auto longestPalindrome( std::string const& s ) -> std::string;
};

} // namespace lc::t5

#endif // LC_31_NEXTPERMUTATION_H
