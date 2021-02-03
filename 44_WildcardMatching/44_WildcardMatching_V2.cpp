#include "44_WildcardMatching_V2.h"

#include <vector>

namespace lc::t44 {

namespace {

//------------------------------
using Char = std::string::value_type;

//------------------------------
[[nodiscard]]
constexpr
auto cmp( Char s, Char p ) noexcept -> bool {
    return (p == '?') ? true : (s == p);
}

//------------------------------
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p )
        -> bool {
    if ( true == s.empty() ) {
        return p.empty() || (p == "*");
    }
    auto prev = std::vector<bool>( s.size() + 1 );
    auto curr = std::vector<bool>( s.size() + 1 );
    auto min_valid = std::size_t{0};
    auto none_star_cnt = std::size_t{0};
    prev[ 0 ] = true;
    curr[ 0 ] = true;
    for ( auto pc : p ) {
        const auto start_ind = std::max( min_valid, none_star_cnt );
        // это "эффективное" начало массива (с учетом добавленного в начало элемента
        const auto curr_begin = curr.begin() + 1;
        // этот if вместо такого цикла, он быстрее а первые элементы мы в итоге не используем
//        std::fill( curr_begin, curr_begin + start_ind, false );
        if ( start_ind != 0 ) {
            curr[ start_ind  ] = false;
        }
        if ( pc != '*' ) {
            ++none_star_cnt;
            for ( auto ci = start_ind; ci < s.size(); ++ci ) {
                curr[ ci + 1 ] = ( prev[ ci ] && cmp( s[ ci ], pc ) );
            }
            const auto first_true = std::find(
                  curr_begin + start_ind
                , curr.end()
                , true
            );
            if ( first_true == curr.end() ) {
                return false;
            }
            min_valid = std::distance( curr_begin, first_true );
        } else {
            const auto start_ind = std::max(
                  min_valid
                // -1 - так как * может быть и пустым символом
                , ( (none_star_cnt == 0) ? none_star_cnt : (none_star_cnt - 1) )
            );
            std::fill( curr_begin + start_ind, curr.end(), true );
        }
        std::swap( curr, prev );
    }
    return prev.back();
}

//------------------------------
[[nodiscard]]
auto removeMultiStars( std::string&& p ) noexcept -> std::string {
    auto ind = std::size_t{1};
    auto prev = p.front();
    for ( auto i = std::size_t{1}; i < p.size(); ++i ) {
        if ( (prev != '*') || (p[i] != '*') ) {
            prev = p[i];
            p[ind] = p[i];
            ++ind;
        }
    }
    p.resize( ind );
    return std::move( p );
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution_V2::isMatch(
              std::string const& s
            , std::string p )
        -> bool {
    if ( true == p.empty() ) {
        return s.empty();
    }
    return isMatchImpl(
          s
        , removeMultiStars( std::move( p ) )
    );
}

} // namespace lc::t44
