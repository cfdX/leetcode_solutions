#ifndef LC_14_LONGESTCOMMONPREFIX_H
#define LC_14_LONGESTCOMMONPREFIX_H

#include <vector>
#include <string>

namespace lc::t14 {

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto longestCommonPrefix(
                std::vector<std::string> const& strs )
            -> std::string;
};

} // namespace lc::t14

#endif // LC_14_LONGESTCOMMONPREFIX_H
