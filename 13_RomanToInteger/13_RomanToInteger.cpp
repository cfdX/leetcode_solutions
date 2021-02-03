#include "13_RomanToInteger.h"

#include <array>

namespace lc::t13 {

namespace {

//------------------------------
// std::string_view::start_with есть только с C++20
[[nodiscard]]
auto startsWith(
              std::string_view const str
            , std::string_view const patt ) noexcept
        -> bool {
    if ( str.size() < patt.size() ) {
        return false;
    }
    for ( std::size_t i = 0; i < patt.size(); ++i ) {
        if ( str[i] != patt[i] ) {
            return false;
        }
    }
    return true;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::romanToInt( std::string_view sv ) noexcept -> int {
    struct Dig {
        int val;
        std::string_view pattern;
    };
    using namespace std::string_view_literals;;
    static constexpr const auto digits = std::array<Dig, 13>{
       Dig{ 1000, "M"sv }
        , { 900,  "CM"sv }
        , { 500,  "D"sv }
        , { 400,  "CD"sv }
        , { 100,  "C"sv }
        , { 90,   "XC"sv }
        , { 50,   "L"sv }
        , { 40,   "XL"sv }
        , { 10,   "X"sv }
        , { 9,    "IX"sv }
        , { 5,    "V"sv }
        , { 4,    "IV"sv }
        , { 1,    "I"sv }
    };
    auto res = int{ 0 };
    for ( const auto& d : digits ) {
        while ( startsWith( sv, d.pattern ) ) {
            sv.remove_prefix( d.pattern.size() );
            res += d.val;
        }
    }
    return res;
}

} // namespace lc::t13
