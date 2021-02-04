#ifndef LC_LISTNODE_H
#define LC_LISTNODE_H

#include <vector>

namespace lc {

//------------------------------
// отсортировали порядок чисел в каждом массиве
// и потом сам порядок массивов
// чтоб сранивать было удобно
[[nodiscard]]
auto sortVectorAndSubVectors(
            std::vector<std::vector<int>>&& res )
        -> std::vector<std::vector<int>>;

} // namespace lc

#endif // LC_LISTNODE_H

