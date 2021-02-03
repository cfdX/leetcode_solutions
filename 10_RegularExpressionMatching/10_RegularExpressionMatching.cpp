#include "10_RegularExpressionMatching_V2.h"

#include <vector>

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
auto skip1( std::string_view s ) -> std::string_view {
    return s.substr( 1, s.size() - 1 );
}

//------------------------------
[[nodiscard]]
constexpr
auto isStarred( Char const c ) -> bool {
    return (c == '?') || static_cast<bool>(std::isupper(c));
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
class Memoizer;
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p
            , Memoizer& cache )
        -> bool;

//------------------------------
// Это штука заполняет кэш для ускорения (в каком-то смысле это мемоизация)
// Можно легко от нее избавиться - заменив вызовы на вызовы isMatchImpl
class Memoizer {
public:
    //------------------------------
    Memoizer( std::string_view s )
        : m_memoizer( s.size() + 1 )
    {}
    //------------------------------
    [[nodiscard]]
    auto callIsMatchImpl(
                  std::string_view s
                , std::string_view p )
            -> bool {
        auto& c = m_memoizer[ s.size() ];
        if ( true == c.empty() ) {
            c = std::vector<bool>( p.size() + 1, false );
        }
        if ( c[ p.size() ] == false ) {
            c[ p.size() ] = true;
            return isMatchImpl( s, p, *this );
        }
        return false;
    }
private:
    std::vector<std::vector<bool>> m_memoizer;
};

//------------------------------
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p
            , Memoizer& memoizer )
        -> bool {
    if ( true == s.empty() ) {
        return isMaybeEmptyPattern( p );
    }
    if ( true == p.empty() ) {
        return false;
    }
    while ( (false == s.empty()) && (false == p.empty()) ) {
        const auto fp = p[ 0 ];
        const auto is_starred = isStarred( fp );
        const auto curr_sym =
                      is_starred
                    ? ( (fp == '?') ? '.' : static_cast<Char>(std::tolower(fp)) )
                    : fp;
        p = skip1( p );
        if ( true == is_starred ) {
            while ( ( s.empty() == false ) && ( true == cmp( s.front(), curr_sym ) ) ) {
                if ( true == memoizer.callIsMatchImpl( s, p ) ) {
                    return true;
                }
                s = skip1( s );
            }
            if ( true == memoizer.callIsMatchImpl( s, p ) ) {
                return true;
            }
            return s.empty() && isMaybeEmptyPattern( p );
        }
        if ( false == cmp( s.front(), curr_sym ) ) {
            return false;
        }
        s = skip1( s );
    }
    if ( true == s.empty() ) {
        return isMaybeEmptyPattern( p );
    }
    return false;
}

} // namespace {

//------------------------------
// лобовое решение с мемоизацией
[[nodiscard]]
auto Solution_V2::isMatch(
              std::string const& s
            , std::string p )
        -> bool {
    const auto pp = processPattern( std::move( p ) );
    auto memoizer = Memoizer{ s };
    return isMatchImpl( s, pp, memoizer );
}

} // namespace lc::t10


