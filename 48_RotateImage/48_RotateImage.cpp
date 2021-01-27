#include "48_RotateImage.h"

#include <algorithm>

namespace lc::t48 {

namespace {

//------------------------------
using Matr = std::vector<std::vector<int>>;

//------------------------------
void transpose( Matr& matr ) noexcept {
    const auto cnt = matr.size();
    for ( std::size_t i = 0; i < cnt; ++i ) {
        for ( std::size_t j = i+1; j < cnt; ++j ) {
            std::swap( matr[i][j], matr[j][i] );
        }
    }
}

//------------------------------
void mirrorRows( Matr& matr ) noexcept {
    for ( auto& row : matr ) {
        // наверное, не очень честно использовать тут алгоритм
        // но уж отзеркалить массив я смогу, просто мне лень
        std::reverse( row.begin(), row.end() );
    }
}

} // namespace {

//------------------------------
void Solution::rotate( Matr& matrix ) noexcept {
    transpose( matrix );
    mirrorRows( matrix );
}

} // namespace lc::t48
