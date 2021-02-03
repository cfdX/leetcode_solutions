#include "10_RegularExpressionMatching.h"

#include <vector>
#include <optional>

namespace lc::t10 {

namespace {

//------------------------------
using Char = std::string::value_type;

//------------------------------
[[nodiscard]]
constexpr
auto cmp( Char const s, Char const p ) noexcept -> bool {
    return ( p == '.' ) ? true : (p == s);
}

//------------------------------
// удаляем двойные **, заменяем повторные символы на верхний регистр
// так нам легче потом работать
[[nodiscard]]
auto processPattern( std::string&& p ) noexcept -> std::string {
    if ( true == p.empty() ) {
        return std::move(p);
    }
    auto ind = std::size_t{1};
    for ( std::size_t i = 1; i < p.size(); ++i ) {
        const auto curr = p[i];
        if ( curr != '*' ) {
            p[ ind ] = curr;
            ++ind;
        } else {
            const auto prev = ind - 1;
            p[ prev] = ( p[ prev ] == '.' ) ? '?' : std::toupper( p[ prev ] );
        }
    }
    p.resize( ind );
    return std::move(p);
}

//------------------------------
[[nodiscard]]
constexpr
auto isStarred( Char const c ) -> bool {
    return (c == '?') || static_cast<bool>(std::isupper(c));
}

//------------------------------
struct CharDesc {
    Char symbol;
    bool is_question_mark;
    bool is_stared;
};

//------------------------------
[[nodiscard]]
constexpr
auto charInfo( Char const c ) -> CharDesc {
    if ( c == '?' ) {
        return { '.', true, true };
    }
    if ( c == '.' ) {
        return { '.', true, false };
    }
    if ( true == static_cast<bool>(std::isupper( c )) ) {
        return { static_cast<char>(std::tolower(c)), false, true };
    }
    return { c, false, false};
}

//------------------------------
[[nodiscard]]
constexpr
auto isMaybeEmptyPattern( std::string_view p ) -> bool {
    for ( auto c : p ) {
        if ( false == isStarred(c) ) {
            return false;
        }
    }
    return true;
}

//------------------------------
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p )
        -> bool {
    if ( true == s.empty() ) {
        return p.empty() || isMaybeEmptyPattern(p);
    }
    auto prev = std::vector<bool>( s.size() + 1 );
    auto curr = std::vector<bool>( s.size() + 1 );
    auto min_valid = std::size_t{0};
    auto none_star_cnt = std::size_t{0};
    prev[ 0 ] = true;
    curr[ 0 ] = true;
    for ( auto pcu : p ) {
        const auto pc = charInfo( pcu );
        const auto start_ind = std::max( min_valid, none_star_cnt );
        // это "эффективное" начало массива (с учетом добавленного в начало элемента
        const auto curr_begin = curr.begin() + 1;
        // этот if вместо такого цикла, он быстрее а первые элементы мы в итоге не используем
//        std::fill( curr_begin, curr_begin + start_ind, false );
        if ( start_ind != 0 ) {
            curr[ start_ind  ] = false;
        }

        const auto recalcNewMinValid = [&]( std::size_t start ) -> std::optional<std::size_t> {
            const auto first_true = std::find(
                  curr_begin + start
                , curr.end()
                , true
            );
            if ( first_true == curr.end() ) {
                return {};
            }
            return std::distance( curr_begin, first_true );
        };

        if ( false == pc.is_stared ) {
            ++none_star_cnt;
            if ( false == pc.is_question_mark ) {
                for ( auto ci = start_ind; ci < s.size(); ++ci ) {
                    curr[ ci + 1 ] = ( prev[ ci ] && cmp( s[ ci ], pc.symbol ) );
                }
            } else {
                for ( auto ci = start_ind; ci < s.size(); ++ci ) {
                    curr[ ci + 1 ] = prev[ ci ];
                }
            }
            const auto mb_min_valid = recalcNewMinValid( start_ind );
            if ( false == mb_min_valid.has_value() ) {
                return false;
            }
            min_valid = mb_min_valid.value();
        } else if ( (true == pc.is_question_mark) && (true == pc.is_stared) ){
            const auto start_ind = std::max(
                  min_valid
                // -1 - так как .* может быть и пустым символом
                , ( (none_star_cnt == 0) ? none_star_cnt : (none_star_cnt - 1) )
            );
            std::fill( curr_begin + start_ind, curr.end(), true );
        } else if ( (false == pc.is_question_mark) && (true == pc.is_stared) ){
            // так как a* может быть и пустым символом
            curr[ start_ind ] = prev[ start_ind ];
            for ( auto ci = start_ind; ci < s.size(); ++ci ) {
                curr[ ci + 1 ] = prev[ ci + 1] || ( curr[ ci ] && (s[ ci ] == pc.symbol) );
            }
            if ( start_ind != 0 ) {
                const auto mb_min_valid = recalcNewMinValid(
                    start_ind - 1
                );
                if ( false == mb_min_valid.has_value()) {
                    return false;
                }
                min_valid = mb_min_valid.value();
            }
        }
        std::swap( curr, prev );
    }
    return prev.back();
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::isMatch(
              std::string const& s
            , std::string p )
        -> bool {
    if ( true == p.empty() ) {
        return s.empty();
    }
    return isMatchImpl(
          s
        , processPattern( std::move( p ) )
    );
}

} // namespace lc::t10
