#include "49_GroupAnagrams.h"

#include <algorithm>
#include <unordered_map>

namespace lc::t49 {

namespace {
using VecS = std::vector<std::string>;
} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::groupAnagrams(
            std::vector<std::string> const& strs )
        -> std::vector<std::vector<std::string>> {
    auto map = std::unordered_map<std::string, VecS>{};
    // оптимизация, чтоб буфер переиспользовать
    auto sorted_str = std::string{};
    for ( const auto& str: strs ) {
        sorted_str = str;
        std::sort( sorted_str.begin(), sorted_str.end() );
        auto iter = map.find( sorted_str );
        if ( iter == map.end() ) {
            map.insert( { sorted_str, { str } } );
        } else {
            iter->second.push_back( str );
        }
    }
    auto res = std::vector<VecS>{};
    res.reserve( map.size() );
    for ( auto&& pair : map ) {
        res.push_back( std::move( pair.second ) );
    }
    return res;
}

} // namespace lc::t49
