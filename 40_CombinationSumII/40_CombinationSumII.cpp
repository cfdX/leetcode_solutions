#include "40_CombinationSumII.h"

#include <algorithm>

namespace lc::t40 {

namespace {
//------------------------------
using Vec = std::vector<int>;

//------------------------------
// TODO как и в предыдущей задаче - достаточно лобовое решение (подумать)
void impl(
          std::vector<Vec>& res
        , Vec& curr_list
        , Vec& nums
        , std::vector<std::size_t>& repeats_cnt
        , int target ) {
    if ( true == nums.empty() ) {
        return;
    }
    const auto prev_list_size = curr_list.size();
    const auto num = nums.back();
    const auto max_repeats = repeats_cnt.back();
    nums.pop_back();
    repeats_cnt.pop_back();
    auto curr_target = target + num;
    for ( std::size_t i = 0; i <= max_repeats; ++i ) {
        curr_target -= num;
        if ( curr_target == 0 ) {
            res.push_back( curr_list );
            break;
        }
        if ( curr_target < 0 ) {
            break;
        }
        impl( res, curr_list, nums, repeats_cnt, curr_target );
        curr_list.push_back( num );
    }
    nums.push_back( num );
    repeats_cnt.push_back( max_repeats );
    curr_list.resize( prev_list_size );
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::combinationSum2(
              Vec& nums
            , int target )
        -> std::vector<Vec> {
    if ( true == nums.empty() ) {
        return {};
    }
    std::sort( nums.begin(), nums.end() );
    auto repeats_cnt = std::vector<std::size_t>{1};
    for ( std::size_t i = 1; i < nums.size(); ++i ) {
        if ( nums[ i ] != nums[ i - 1 ] ) {
            nums[ repeats_cnt.size() ] = nums[ i ];
            repeats_cnt.push_back( 1 );
        } else {
            ++repeats_cnt.back();
        }
    }
    nums.resize( repeats_cnt.size() );
    auto res = std::vector<Vec>{};
    auto curr = Vec{};
    impl( res, curr, nums, repeats_cnt, target );
    return res;
}

} // namespace lc::t40


