#ifndef LC_10_REGULAREXPRESSIONMATCHING_V2_H
#define LC_10_REGULAREXPRESSIONMATCHING_V2_H

#include <string>

namespace lc::t10 {

/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/

//------------------------------
class Solution_V2 {
public:
    //------------------------------
    // O(s*p) - dynamic programming
    [[nodiscard]]
    static
    auto isMatch(
                  std::string const& s
                , std::string p )
            -> bool;
};

} // namespace lc::t10

#endif // LC_10_REGULAREXPRESSIONMATCHING_V2_H
