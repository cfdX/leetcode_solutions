#include "TestUtils.h"

#include <algorithm>
#include <string>

namespace lc {

//------------------------------
[[nodiscard]]
auto sortVectorAndSubVectors(
            std::vector<std::vector<int>>&& res )
        -> std::vector<std::vector<int>> {
    namespace rng = std::ranges;
    for ( auto& list : res ) {
        rng::sort( list );
    }
    rng::sort( res, std::ref( rng::lexicographical_compare ) );
    return std::move( res );
}

} // namespace lc
