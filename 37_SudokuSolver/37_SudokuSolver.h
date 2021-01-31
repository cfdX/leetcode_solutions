#ifndef LC_37_SUDOKUSOLVER_H
#define LC_37_SUDOKUSOLVER_H

#include <vector>

namespace lc::t37 {

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    static
    void solveSudoku( std::vector<std::vector<char>>& board ) noexcept;
};

} // namespace lc::t37

#endif // LC_37_SUDOKUSOLVER_H
