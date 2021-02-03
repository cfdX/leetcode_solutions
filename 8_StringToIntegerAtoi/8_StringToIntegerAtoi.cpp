#include "8_StringToIntegerAtoi.h"

#include <limits>

namespace lc::t8 {

namespace {
[[nodiscard]]
auto skip1( std::string_view s ) -> std::string_view {
    return s.substr( 1, s.size() - 1 );
}
} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::myAtoi( std::string const& s ) noexcept -> int {
    using Long = std::int64_t;
    using Limits = std::numeric_limits<int>;

    if ( true == s.empty() ) {
        return 0;
    }
    constexpr const auto max = static_cast<Long>( Limits::max() );
    constexpr const auto min = -static_cast<Long>( Limits::lowest() );
    auto str = std::string_view{ s };
    while ( std::isspace( str[0] ) ) {
        str = skip1( str );
        if ( true == str.empty() ) {
            return 0;
        }
    }
    const auto is_minus = str[ 0 ] == '-' ? Long{-1} : Long{1};
    if ( str[ 0 ] == '+' ) {
        str = skip1( str );
        if ( true == str.empty() ) {
            return 0;
        }
    } else if ( -1 == is_minus ) {
        str = skip1( str );
        if ( true == str.empty() ) {
            return 0;
        }
    }
    auto res = Long{0};
    while ( ( str.empty() == false ) && std::isdigit( str[ 0 ] ) ) {
        res = res * 10 + static_cast<Long>( str[ 0 ] - '0' );
        if ( is_minus == 1 ) {
            if ( res > max ) {
                return Limits::max();
            }
        } else {
            if ( res > min ) {
                return Limits::lowest();
            }
        }
        str = skip1( str );
    }

    return static_cast<int>(is_minus*res);
}

} // namespace lc::t8
