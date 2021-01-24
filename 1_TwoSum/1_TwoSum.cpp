#include "1_TwoSum.h"

#include <vector>
#include <unordered_map>

namespace lc::t1 {

//------------------------------
auto Solution::twoSum( std::vector<int>& nums, int target) -> std::vector<int> {
    auto set = std::unordered_map<int, std::size_t>{};
    for ( std::size_t i = 0; i < nums.size(); ++i ) {
        const auto other = set.find( target - nums[i] );
        if ( other != set.end() ) {
            return { static_cast<int>(i), static_cast<int>(other->second) };
        }
        set.insert( { nums[i], i } );
    }
    // [[unreachable]]
    return {};
}

} // namespace lc::t1
