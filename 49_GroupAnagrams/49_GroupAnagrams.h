#ifndef LC_49_GROUPANAGRAMS_H
#define LC_49_GROUPANAGRAMS_H

#include <vector>
#include <string>

namespace lc::t49 {

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

//------------------------------
class Solution {
public:
    //------------------------------
    [[nodiscard]]
    static
    auto groupAnagrams(
            std::vector<std::string> const& strs )
        -> std::vector<std::vector<std::string>>;
};

} // namespace lc::t49

#endif // LC_31_NEXTPERMUTATION_H
