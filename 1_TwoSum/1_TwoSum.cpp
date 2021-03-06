#include "1_TwoSum.h"

#include <vector>
#include <unordered_map>
#include <algorithm>

namespace lc::t1 {

//------------------------------
auto Solution::twoSum1( std::vector<int> const& nums, int target ) -> std::vector<int> {
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

namespace {

//------------------------------
struct NumInd {
    int num;
    std::size_t ind;
};

//------------------------------
auto makeSortedList( std::vector<int> const& nums ) -> std::vector<NumInd> {
    auto nums_inds = std::vector<NumInd>( nums.size() ); // ! с заданным размером !
    std::generate(
              nums_inds.begin()
            , nums_inds.end()
            , [n = std::size_t{0}, &nums] () mutable ->  NumInd {
                const auto ind = std::exchange( n, n + 1 );
                return { nums[ind], ind };
            }
    );
    std::sort(
          nums_inds.begin()
        , nums_inds.end()
        , []( const auto& o1, const auto o2 ) {
            return o1.num < o2.num;
        }
    );
    return nums_inds;
}

} // namespace {

//------------------------------
auto Solution::twoSum2( std::vector<int> const& nums, int target ) -> std::vector<int> {
    const auto nums_inds = makeSortedList( nums );

    for ( std::size_t i = 0; i < nums_inds.size(); ++i ) {
        if ( nums_inds[i].num > target/2 ) {
            // [[unreachable]]
            return {};
        }
        const auto searched = target - nums_inds[i].num;
        const auto second_iter = std::lower_bound(
              nums_inds.begin() + i + 1
            , nums_inds.end(), searched
            , []( const auto& el, const auto& num ){
                return el.num < num;
            }
        );
        if ( second_iter == nums_inds.end() ) {
            continue;
        }
        if ( second_iter->num == searched ) {
            return {
                  static_cast<int>( second_iter->ind )
                , static_cast<int>( nums_inds[i].ind )
            };
        }
    }
    // [[unreachable]]
    return {};
}


//------------------------------
auto Solution::twoSum3( std::vector<int> const& nums, int target ) -> std::vector<int> {
    const auto nums_inds = makeSortedList( nums );
    // нашли сами числа
    auto left = std::size_t{0};
    auto right = nums_inds.size() - 1;
    while ( left < right ) {
        const auto sum = nums_inds[ left ].num + nums_inds[ right ].num;
        if ( sum > target ) {
            --right;
        } else if ( sum < target ) {
            ++left;
        } else {
            return {
                  static_cast<int>( nums_inds[left].ind )
                , static_cast<int>( nums_inds[right].ind )
            };
        }
    }
    // [[unreachable]]
    return {};
}

} // namespace lc::t1
