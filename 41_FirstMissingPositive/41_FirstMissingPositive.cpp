#include "41_FirstMissingPositive.h"

namespace lc::t41 {

//------------------------------
[[nodiscard]]
auto Solution::firstMissingPositive(
            std::vector<int>& nums ) noexcept
        -> int {
    const auto process_i = [&]( std::size_t i ) -> bool {
        // ставим -1 (или оставляем отрицательное число
        // на месте элемента
        const auto n = std::exchange( nums[i], -1 );
        if ( n <= 0 ) {
            return true;
        }
        const auto x = static_cast<std::size_t>(n) - 1;
        if ( x >= nums.size() ) {
            // мы уверены, что отсутствующее число - одно из N первых положительных
            // соответственно, остальные нам не интересны
            return true;
        }
        if ( x <= i ) {
            // пометили, соответствующий элемент, есть в массиве
            nums[x] = 0;
            return true;
        }
        if ( nums[x] == n ) {
            // нам еще встретится это число
            return true;
        }
        // это swap значений элементов в массиве
        nums[i] = nums[x];
        nums[x] = n;
        // говорим, что нужно повторить
        return false;
    };
    for ( std::size_t i = 0; i < nums.size(); ++i ) {
        // может показаться, что этот цикл портит сложность
        // но это не так.
        // в результате выполнения process_i мы либо помечаем один элемент
        // исходного массива, либо устаналиваем один элемент на его место (индекс==значению)
        // а значит мы не можем поставить более n пометок или сделать более n таких перестановок
        while ( false == process_i( i ) ) {
            // should be empty
        }
    }
    const auto it = std::find(
        nums.begin(), nums.end(), -1
    );
    return static_cast<int>(
        std::distance( nums.begin(), it )
    ) + 1;
}

} // namespace lc::t41
