#include "44_WildcardMatching.h"

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
constexpr
auto subStr( std::string_view s, std::size_t i ) noexcept -> std::string_view {
    return s.substr( i, s.size() - i );
}

//------------------------------
class Memoizer;
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p
            , Memoizer& memoizer )
        -> bool;

//------------------------------
class Memoizer {
public:
    //------------------------------
    Memoizer( std::string_view p, std::string_view s )
        : m_memoizer( p.size() + 1 )
        , m_str_size{ s.size() }
    {}
    //------------------------------
    [[nodiscard]]
    auto callIsMatchImpl(
                  std::string_view s
                , std::string_view p )
            -> bool {
        if ( true == m_memoizer[ p.size() ].empty() ) {
            m_memoizer[ p.size() ].resize( m_str_size + 1, false );
        }
        if ( m_memoizer[ p.size() ][ s.size() ] == true ) {
            return false;
        }
        m_memoizer[ p.size() ][ s.size() ] = true;
        return isMatchImpl( s, p, *this );
    }
private:
    std::vector<std::vector<bool>> m_memoizer;
    std::size_t const m_str_size;
};


//------------------------------
[[nodiscard]]
auto isMatchImpl(
              std::string_view s
            , std::string_view p
            , Memoizer& memoizer )
        -> bool {
    if ( true == p.empty() ) {
        return s.empty();
    }
    for ( auto pi = std::size_t{0}; pi < p.size(); ++pi ) {
        const auto pc = p[ pi ];
        const auto is_star = pc == '*';
        const auto sub_p = subStr( p, pi + 1 );
        if ( true == s.empty() ) {
            return (true == is_star) && (true == sub_p.empty());
        }
        if ( true == is_star ) {
            for ( auto si = std::size_t{0}; si <= s.size(); ++si ) {
                if ( true == memoizer.callIsMatchImpl( subStr( s, si ), sub_p ) ) {
                    return true;
                }
            }
            return false;
        }
        if ( true == cmp( s.front(), pc ) ) {
            s = subStr( s, 1 );
            continue;
        } else {
            return false;
        }
    }
    return s.empty();
}

//------------------------------
[[nodiscard]]
auto removeMultiStars( std::string&& p ) noexcept -> std::string {
    if ( true == p.empty() ) {
        return std::move( p );
    }
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
// лобовое решение с мемоизацией
// в V2 - через динамическое программирование
[[nodiscard]]
auto Solution::isMatch(
              std::string const& s
            , std::string p )
        -> bool {
    p = removeMultiStars( std::move( p ) );
    auto memoizer = Memoizer{ p, s };
    return isMatchImpl( s, p, memoizer );
}

} // namespace lc::t44
