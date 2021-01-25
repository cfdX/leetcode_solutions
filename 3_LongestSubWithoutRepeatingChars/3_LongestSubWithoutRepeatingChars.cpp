#include "3_LongestSubWithoutRepeatingChars.h"

#include <array>

namespace lc::t3 {

auto Solution::lengthOfLongestSubstring(
            std::string const& str ) noexcept
        -> int {
    auto prev_ind = std::array<std::size_t,256>{};
    auto substr_start = std::size_t{0};
    auto max_len = std::size_t{0};
    for ( std::size_t i = 0; i < str.size(); ++i ) {
        // TODO! если символ знаковый и интерпретация символа отрицательна, я не уверен как это отработает
        const auto ci = static_cast<std::size_t>( str[i] );
//        if ( ci > 256 ) { return -1; }
        substr_start = std::max( substr_start, prev_ind[ci] );
        const auto curr_len = static_cast<int>(i) - substr_start + 1;
        max_len = std::max( max_len, curr_len );
        prev_ind[ci] = i + 1;
    }
    return static_cast<int>(max_len);
}

} // namespace lc::t3
