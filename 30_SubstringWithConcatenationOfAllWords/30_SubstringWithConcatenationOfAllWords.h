#ifndef LC_30_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
#define LC_30_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H

#include <vector>
#include <string>
#include <string_view>

namespace lc::t30 {

/*
You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto findSubstring(
                  std::string_view s
                , std::vector<std::string> const& words )
            -> std::vector<int>;
};

} // namespace lc::t30

#endif // LC_30_SUBSTRINGWITHCONCATENATIONOFALLWORDS_H
