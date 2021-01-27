cmake_minimum_required(VERSION 3.14)

project(leetcode_solutions LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Catch2)
include_directories(Catch2/src/catch2)

add_executable(leetcode_solutions
  main.cpp
  ListNode.cpp
  ListNode.h
  ListNode_t.cpp
  1_TwoSum/1_TwoSum.h
  1_TwoSum/1_TwoSum.cpp
  1_TwoSum/1_TwoSum_t.cpp
  2_AddTwoNumbers/2_AddTwoNumbers.h
  2_AddTwoNumbers/2_AddTwoNumbers.cpp
  2_AddTwoNumbers/2_AddTwoNumbers_t.cpp
  3_LongestSubWithoutRepeatingChars/3_LongestSubWithoutRepeatingChars.h
  3_LongestSubWithoutRepeatingChars/3_LongestSubWithoutRepeatingChars.cpp
  3_LongestSubWithoutRepeatingChars/3_LongestSubWithoutRepeatingChars_t.cpp
  31_NextPermutation/31_NextPermutation.h
  31_NextPermutation/31_NextPermutation.cpp
  31_NextPermutation/31_NextPermutation_t.cpp
  32_LongestValidParentheses/32_LongestValidParentheses.h
  32_LongestValidParentheses/32_LongestValidParentheses.cpp
  32_LongestValidParentheses/32_LongestValidParentheses_t.cpp
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr.h
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr.cpp
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr_t.cpp
  41_FirstMissingPositive/41_FirstMissingPositive.h
  41_FirstMissingPositive/41_FirstMissingPositive.cpp
  41_FirstMissingPositive/41_FirstMissingPositive_t.cpp
  46_Permutations/46_Permutations.h
  46_Permutations/46_Permutations.cpp
  46_Permutations/46_Permutations_t.cpp
  47_PermutationsII/47_PermutationsII.h
  47_PermutationsII/47_PermutationsII.cpp
  47_PermutationsII/47_PermutationsII_t.cpp
  48_RotateImage/48_RotateImage.h
  48_RotateImage/48_RotateImage.cpp
  48_RotateImage/48_RotateImage_t.cpp
  49_GroupAnagrams/49_GroupAnagrams.h
  49_GroupAnagrams/49_GroupAnagrams.cpp
  49_GroupAnagrams/49_GroupAnagrams_t.cpp
  Catch2/src/catch2/catch_all.hpp
)
target_link_libraries(leetcode_solutions Catch2::Catch2)
