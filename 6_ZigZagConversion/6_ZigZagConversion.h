#ifndef LC_6_ZIGZAGCONVERSION_H
#define LC_6_ZIGZAGCONVERSION_H

#include <string>

namespace lc::t6 {

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto convert( std::string const& s, int numRows) -> std::string;
};

} // namespace lc::t6

#endif // LC_6_ZIGZAGCONVERSION_H
