#include "49_GroupAnagrams.h"

#include <algorithm>

namespace lc::t49 {

//------------------------------
[[nodiscard]]
auto Solution::groupAnagrams(
            std::vector<std::string> const& strs )
        -> std::vector<std::vector<std::string>> {
    auto sorted_base = std::vector<std::string>{};
    auto res = std::vector<std::vector<std::string>>{};
    auto sorted_str = std::string{};
    for ( const auto& str: strs ) {
        sorted_str = str;
        std::sort( sorted_str.begin(), sorted_str.end() );
        const auto iter = std::lower_bound(
              sorted_base.begin()
            , sorted_base.end()
            , sorted_str
        );
        const auto dist = std::distance(
              sorted_base.begin()
            , iter
        );
        if ( ( iter == sorted_base.end() ) || (*iter != sorted_str) ) {
            sorted_base.insert( iter, sorted_str );
            res.insert( res.begin() + dist, { str } );
        } else {
            res[ dist ].push_back( str );
        }
    }
    return res;
}

} // namespace lc::t49
