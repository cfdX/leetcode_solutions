#include "9_PalindromeNumber.h"

#include <cstdint>

namespace lc::t9 {

//------------------------------
[[nodiscard]]
auto Solution::isPalindrome( int x ) noexcept -> bool {
    if ( x < 0 ) {
        return false;
    }
    using Long = std::int64_t;
    const auto xl = static_cast<Long>(x);
    auto y = xl;
    auto reversed = Long{0};
    while ( y > 0 ) {
        reversed = (reversed * 10) + (y % 10);
        y = y / 10;
    }
    return reversed == xl;
}

} // namespace lc::t9
