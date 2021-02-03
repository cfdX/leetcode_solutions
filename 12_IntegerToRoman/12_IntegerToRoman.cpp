#include "12_IntegerToRoman.h"

#include <array>

namespace lc::t12 {

//------------------------------
[[nodiscard]]
auto Solution::intToRoman( int num ) -> std::string {
    struct Dig {
        int val;
        using Func = void (*)( std::string& );
        Func appender;
    };
    // я не знаю, как будет быстрее - хранить функции. Или хранить строки.
    static constexpr const auto digits = std::array<Dig, 13>{
       Dig{ 1000, []( std::string& s ){ s += 'M'; } }
        , { 900,  []( std::string& s ){ s += "CM"; } }
        , { 500,  []( std::string& s ){ s += 'D'; } }
        , { 400,  []( std::string& s ){ s += "CD"; } }
        , { 100,  []( std::string& s ){ s += 'C'; } }
        , { 90,   []( std::string& s ){ s += "XC"; } }
        , { 50,   []( std::string& s ){ s += 'L'; } }
        , { 40,   []( std::string& s ){ s += "XL"; } }
        , { 10,   []( std::string& s ){ s += 'X'; } }
        , { 9,    []( std::string& s ){ s += "IX"; } }
        , { 5,    []( std::string& s ){ s += 'V'; } }
        , { 4,    []( std::string& s ){ s += "IV"; } }
        , { 1,    []( std::string& s ){ s += 'I'; } }
    };
    auto res = std::string{};
    for ( const auto& d : digits ) {
        while ( num >= d.val ) {
            num -= d.val;
            d.appender( res );
        }
    }
    return res;
}

} // namespace lc::t12
