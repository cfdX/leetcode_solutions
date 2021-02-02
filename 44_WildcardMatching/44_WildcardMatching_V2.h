#ifndef LC_44_WILDCARDMATCHING_V2_H
#define LC_44_WILDCARDMATCHING_V2_H

#include <string>

namespace lc::t44 {

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

//------------------------------
class Solution_V2 {
public:
    //------------------------------
    // решение за O(s.size()*p.size())
    // и O(s.size()) доп памяти
    [[nodiscard]]
    static
    auto isMatch(
                  std::string const& s
                , std::string p )
            -> bool;
};

} // namespace lc::t44

#endif // LC_44_WILDCARDMATCHING_V2_H
