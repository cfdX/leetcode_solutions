#include "32_LongestValidParentheses.h"

namespace lc::t32 {

namespace {

//------------------------------
struct CountResult {
    int max_valid_len = 0;
    bool end_of_string_is_valid = false;
};

//------------------------------
template<class Iter>
[[nodiscard]]
auto count(
              Iter begin
            , Iter end
            , std::string::value_type const open_char ) noexcept
        -> CountResult {
    auto opened_cnt = int{0};
    auto max_len = 0;
    auto curr_len = 0;
    for ( ; begin != end; ++begin ) {
        const auto c = *begin;
        if ( c == open_char ) {
            ++opened_cnt;
            ++curr_len;
        } else {
            --opened_cnt;
            if ( opened_cnt == 0 ) {
                max_len = std::max( max_len, 2*curr_len );
            } else if ( opened_cnt < 0 ) {
                opened_cnt = 0;
                curr_len = 0;
            }
        }
    }
    return { max_len, opened_cnt == 0 };
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::longestValidParentheses(
            std::string const& s ) noexcept
        -> int {
    if ( true == s.empty() ) {
        return 0;
    }
    const auto direct_order_res = count(
        s.begin(), s.end(), '('
    );
    if ( true == direct_order_res.end_of_string_is_valid ) {
        return direct_order_res.max_valid_len;
    }
    const auto reverse_order_res = count(
        s.rbegin(), s.rend(), ')'
    );
    return std::max(
          direct_order_res.max_valid_len
        , reverse_order_res.max_valid_len
    );
}

} // namespace lc::t32
