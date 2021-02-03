#include "8_StringToIntegerAtoi.h"

#include <limits>
#include <algorithm>

namespace lc::t8 {

//------------------------------
[[nodiscard]]
auto Solution::myAtoi( std::string const& s ) noexcept -> int {
    using Long = std::int64_t;
    using Lims = std::numeric_limits<int>;

    const auto end = s.end();
    auto pos = std::find_if_not( s.begin(), end, []( auto c ) { return c == ' '; } );
//    auto pos = std::find_if_not( s.begin(), end, &std::isspace );
    if ( pos == end ) {
        return 0;
    }

    const auto is_positive = (*pos != '-');
    // пропустили плюс или минус
    if ( (*pos == '+') || ( false == is_positive )) {
        ++pos;
        if ( pos == end ) {
            return 0;
        }
    }

    auto res = Long{0};
    const auto limit_res = is_positive ? Lims::max() : Lims::lowest();
    const auto limit =
              is_positive
            ? static_cast<Long>( Lims::max() )
            : -static_cast<Long>( Lims::lowest() );
    while ( ( pos != end ) && std::isdigit( *pos ) ) {
        res = res * 10 + static_cast<Long>( *pos - '0' );
        if ( res > limit ) {
            return limit_res;
        }
        ++pos;
    }

    return static_cast<int>(is_positive ? res : -res);
}

} // namespace lc::t8
