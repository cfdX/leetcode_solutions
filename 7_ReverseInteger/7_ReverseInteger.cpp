#include "7_ReverseInteger.h"

#include <limits>

namespace lc::t7 {

//------------------------------
[[nodiscard]]
auto Solution::reverse( int x ) noexcept -> int {
    if ( x == std::numeric_limits<int>::lowest() ) {
        return 0;
    }
    const auto sign = x > 0;
    x = sign ? x : -x;
    auto res = int{0};
    constexpr const auto max = std::numeric_limits<int>::max();
    constexpr const auto max_10 = max / 10;
    while ( x > 0 ) {
        // чтоб не переполнить int
        if ( res > max_10 ) {
            return 0;
        }
        const auto new_first = res*10;
        const auto new_last = x%10;
        // чтоб не переполнить int
        if ( max - new_first < new_last ) {
            return 0;
        }
        res = new_first + new_last;
        x = x / 10;
    }
    return sign ? res : -res;
}

} // namespace lc::t7
