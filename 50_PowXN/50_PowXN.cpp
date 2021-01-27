#include "50_PowXN.h"

#include <cstdint>

namespace lc::t50 {

namespace {

using i64 = std::int64_t;

//------------------------------
[[nodiscard]]
auto powImpl( double x, i64 n ) noexcept -> double {
    auto curr_sq = x;
    // возможно это не очень честно, что я использую i64
    // чтоб избежать переполнения
    // с другом стороны, в обратном случае можно добавить один if
    auto curr_n = static_cast<i64>(1);
    auto res = double{1.};
    while ( curr_n <= n ) {
        if ( (curr_n&n) != static_cast<i64>(0) ) {
            res *= curr_sq;
        }
        curr_n <<= 1;
        curr_sq *= curr_sq;
    }
    return res;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::myPow( double x, int n ) noexcept -> double {
    return
          (n >= 0)
        ? powImpl( x, static_cast<i64>(n) )
        : 1./powImpl( x, -static_cast<i64>(n));
}

} // namespace lc::t50
