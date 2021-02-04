#include "14_LongestCommonPrefix.h"

namespace lc::t14 {

//------------------------------
[[nodiscard]]
auto Solution::longestCommonPrefix(
            std::vector<std::string> const& strs )
        -> std::string {
    if ( true == strs.empty() ) {
        return {};
    }
    auto res = std::string_view{ strs[0] };
    for ( std::size_t si = 1; si < strs.size(); ++si ) {
        if ( true == res.empty() ) {
            return {};
        }
        const auto& s = strs[ si ];
        const auto lim = std::min( s.size(), res.size() );
        auto i = std::size_t{0};
        while ( i < lim ) {
            if ( s[ i ] != res[ i ] ) {
                break;
            }
            ++i;
        }
        res.remove_suffix( res.size() - i );
    }
    return std::string{ res };
}

} // namespace lc::t14
