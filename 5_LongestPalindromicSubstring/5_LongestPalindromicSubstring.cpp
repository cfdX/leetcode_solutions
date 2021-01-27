#include "5_LongestPalindromicSubstring.h"

namespace lc::t5 {

namespace {

//------------------------------
[[nodiscard]]
auto returnPoly(
              std::string const& s
            , std::size_t l
            , std::size_t r )
        -> std::string_view {
    const auto start_r = r;
    auto cnt = std::size_t{0};
    while ( true ) {
        if ( s[ l ] != s[ r ] ) {
            break;
        }
        ++cnt;
        if ( l == 0 ) {
            break;
        }
        --l;
        if ( r == s.size() - 1 ) {
            break;
        }
        ++r;
    }
    return std::string_view{ s }.substr( start_r, cnt );
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::longestPalindrome( std::string const& s ) -> std::string {
    if ( s.size() < 2 ) {
        return s;
    }
    auto res = std::string_view{};
    auto curr_size = std::size_t{0};
    for ( std::size_t i = 0; i < s.size() - 1; ++i ) {
        {
            const auto curr_res1 = returnPoly( s, i, i );
            const auto size1 = curr_res1.size()*2 - 1;
            if ( curr_size < size1 ) {
                curr_size = size1;
                res = curr_res1;
            }
        }
        {
            const auto curr_res2 = returnPoly( s, i, i + 1 );
            const auto size2 = curr_res2.size()*2;
            if ( curr_size < size2 ) {
                curr_size = size2;
                res = curr_res2;
            }
        }
    }
    auto res_str = std::string( curr_size, ' ' );
    const auto shift = curr_size/2;
    for ( std::size_t i = 0; i < res.size(); ++i ) {
        res_str[ i ] = res[ res.size() - i - 1 ];
        res_str[ i + shift ] = res[ i ];
    }
    return res_str;
}

} // namespace lc::t5
