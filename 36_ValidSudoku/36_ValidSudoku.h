#ifndef LC_36_VALIDSUDOKU_H
#define LC_36_VALIDSUDOKU_H

#include <vector>

namespace lc::t36 {

/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto isValidSudoku(
                std::vector<std::vector<char>> const& board ) noexcept
            -> bool;
};

} // namespace lc::t36

#endif // LC_36_VALIDSUDOKU_H
