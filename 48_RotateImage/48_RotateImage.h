#ifndef LC_48_ROTATEIMAGE_H
#define LC_48_ROTATEIMAGE_H

#include <vector>

namespace lc::t48 {

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    static
    void rotate( std::vector<std::vector<int>>& matrix ) noexcept;
};

} // namespace lc::t48

#endif // LC_48_ROTATEIMAGE_H
