#ifndef LC_44_WILDCARDMATCHING_H
#define LC_44_WILDCARDMATCHING_H

#include <string>

namespace lc::t44 {

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto isMatch(
                  std::string const& s
                , std::string p )
            -> bool;
};

} // namespace lc::t44

#endif // LC_44_WILDCARDMATCHING_H
