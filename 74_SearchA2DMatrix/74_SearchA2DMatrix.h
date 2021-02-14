#ifndef LC_74_SEARCHA2DMATRIX_H
#define LC_74_SEARCHA2DMATRIX_H

#include <vector>

namespace lc::t74 {

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto searchMatrix(
                  std::vector<std::vector<int>> const& matrix
                , int target ) noexcept
            -> bool;

};

} // namespace lc::t74

#endif // LC_74_SEARCHA2DMATRIX_H
