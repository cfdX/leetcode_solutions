#ifndef LC_50_POWXN_H
#define LC_50_POWXN_H

namespace lc::t50 {

/*
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
*/

//------------------------------
class Solution {
public:
    //------------------------------
    // O(logn). no recursion or extra memory
    [[nodiscard]]
    static
    auto myPow( double x, int n ) noexcept -> double;
};

} // namespace lc::t50

#endif // LC_31_NEXTPERMUTATION_H
