#include "39_CombinationSum.h"

namespace lc::t39 {

namespace {
//------------------------------
using Vec = std::vector<int>;

//------------------------------
// TODO у нас тут рекурсия длинной в массив кандидатов (вроде до 200)
// в целом это совершенно лабовое решение. Но у меня башка уже не варит
// потом нужно будет таки подумать
void impl( std::vector<Vec>& res, Vec& curr_list, Vec& nums, int target ) {
    if ( true == nums.empty() ) {
        return;
    }
    const auto prev_list_size = curr_list.size();
    const auto num = nums.back();
    nums.pop_back();
    while ( target > 0 ) {
        impl( res, curr_list, nums, target );
        curr_list.push_back( num );
        target -= num;
        if ( target == 0 ) {
            res.push_back( curr_list );
        }
    }
    nums.push_back( num );
    curr_list.resize( prev_list_size );
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::combinationSum(
              Vec& candidates
            , int target )
        -> std::vector<Vec> {
    auto res = std::vector<Vec>{};
    auto curr = Vec{};
    impl( res, curr, candidates, target );
    return res;
}

} // namespace lc::t39
