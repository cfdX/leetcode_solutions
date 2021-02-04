#include "15_3Sum.h"

#include <algorithm>

namespace lc::t15 {

namespace {

using Vec = std::vector<int>;

//------------------------------
[[nodiscard]]
auto skip( Vec const& nums, std::size_t ind ) -> std::size_t {
    const auto el = nums[ ind ];
    // тут можно юзать бинарный поиск, но я предполагаю, что одинаковых элементов
    // будет не очень много и линейный алгоритм будет быстрее
    while ( (ind < nums.size()) && (nums[ ind ] == el ) ) {
        ++ind;
    }
    return ind;
}

//------------------------------
[[nodiscard]]
auto skipRight( Vec const& nums, std::size_t ind ) -> std::size_t {
    const auto el = nums[ ind ];
    // тут можно юзать бинарный поиск, но я предполагаю, что одинаковых элементов
    // будет не очень много и линейный алгоритм будет быстрее
    while ( (ind > 0) && (nums[ ind ] == el ) ) {
        --ind;
    }
    return ind;
}

} // namespace {

//------------------------------
[[nodiscard]]
auto Solution::threeSum( Vec& nums ) -> std::vector<Vec> {
    if ( nums.size() < 3 ) {
        return {};
    }
    std::sort( nums.begin(), nums.end() );
    auto res = std::vector<Vec>{};
    for ( std::size_t i = 0; i < nums.size() - 2; i = skip( nums, i ) ) {
        if ( nums[i] + nums[i+1] + nums[i+2] > 0 ) {
            return res;
        }
        auto left_ind = i+1;
        auto right_ind = nums.size()-1;
        while( left_ind < right_ind ) {
            const auto val = nums[i] + nums[left_ind] + nums[right_ind];
            if ( val > 0 ) {
                right_ind = skipRight( nums, right_ind );
            } else if ( val < 0 ) {
                left_ind = skip( nums, left_ind );
            } else {
                res.push_back( { nums[i], nums[left_ind], nums[right_ind] } );
                left_ind = skip( nums, left_ind );
                right_ind = skipRight( nums, right_ind );
            }
        }
    }
    return res;
}

} // namespace lc::t15
