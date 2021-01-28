#include "6_ZigZagConversion.h"

namespace lc::t6 {

//------------------------------
[[nodiscard]]
auto Solution::convert( std::string const& s, int numRows ) -> std::string {
    if ( numRows < 2 ) {
        return s;
    }
    auto res = std::string();
    res.reserve( s.size() );
    const auto rows = static_cast<std::size_t>(numRows);
    const auto zig_size = numRows*2 - 2;
    for ( std::size_t ri = 0; ri < rows; ++ri ) {
        const auto is_edge = (ri == 0) || (ri == rows - 1);
        const auto second_j_shift = zig_size - 2*ri;
        for ( std::size_t j = ri; j < s.size(); j += zig_size ) {
            res.push_back( s[ j ] );
            if ( false == is_edge  ) {
                const auto second_j = j + second_j_shift;
                if ( second_j < s.size() ) {
                    res.push_back( s[ second_j ] );
                }
            }
        }
    }
    return res;
}

} // namespace lc::t6
