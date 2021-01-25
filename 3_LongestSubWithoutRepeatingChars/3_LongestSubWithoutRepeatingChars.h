#ifndef LC_3_LONGESTSUBWITHOUTREPEATINGCHARS_H
#define LC_3_LONGESTSUBWITHOUTREPEATINGCHARS_H

#include <string>

namespace lc::t3 {

/*Given a string s, find the length of the longest substring without repeating characters.*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(n) implementation
    [[nodiscard]]
    static
    auto lengthOfLongestSubstring(
                std::string const& str ) noexcept
            -> int;
};

} // namespace lc::t3

#endif // LC_3_LONGESTSUBWITHOUTREPEATINGCHARS_H
