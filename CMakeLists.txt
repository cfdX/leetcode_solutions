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
  5_LongestPalindromicSubstring/5_LongestPalindromicSubstring.h
  5_LongestPalindromicSubstring/5_LongestPalindromicSubstring.cpp
  5_LongestPalindromicSubstring/5_LongestPalindromicSubstring_t.cpp
  6_ZigZagConversion/6_ZigZagConversion.h
  6_ZigZagConversion/6_ZigZagConversion.cpp
  6_ZigZagConversion/6_ZigZagConversion_t.cpp
  7_ReverseInteger/7_ReverseInteger.h
  7_ReverseInteger/7_ReverseInteger.cpp
  7_ReverseInteger/7_ReverseInteger_t.cpp
  8_StringToIntegerAtoi/8_StringToIntegerAtoi.h
  8_StringToIntegerAtoi/8_StringToIntegerAtoi.cpp
  8_StringToIntegerAtoi/8_StringToIntegerAtoi_t.cpp
  9_PalindromeNumber/9_PalindromeNumber.h
  9_PalindromeNumber/9_PalindromeNumber.cpp
  9_PalindromeNumber/9_PalindromeNumber_t.cpp
  10_RegularExpressionMatching/10_RegularExpressionMatching.h
  10_RegularExpressionMatching/10_RegularExpressionMatching.cpp
  10_RegularExpressionMatching/10_RegularExpressionMatching_V2.h
  10_RegularExpressionMatching/10_RegularExpressionMatching_V2.cpp
  10_RegularExpressionMatching/10_RegularExpressionMatching_t.cpp
  11_ContainerWithMostWater/11_ContainerWithMostWater.h
  11_ContainerWithMostWater/11_ContainerWithMostWater.cpp
  11_ContainerWithMostWater/11_ContainerWithMostWater_t.cpp
  12_IntegerToRoman/12_IntegerToRoman.h
  12_IntegerToRoman/12_IntegerToRoman.cpp
  12_IntegerToRoman/12_IntegerToRoman_t.cpp
  13_RomanToInteger/13_RomanToInteger.h
  13_RomanToInteger/13_RomanToInteger.cpp
  13_RomanToInteger/13_RomanToInteger_t.cpp
  14_LongestCommonPrefix/14_LongestCommonPrefix.h
  14_LongestCommonPrefix/14_LongestCommonPrefix.cpp
  14_LongestCommonPrefix/14_LongestCommonPrefix_t.cpp
  15_3Sum/15_3Sum.h
  15_3Sum/15_3Sum.cpp
  15_3Sum/15_3Sum_t.cpp
  30_SubstringWithConcatenationOfAllWords/30_SubstringWithConcatenationOfAllWords.h
  30_SubstringWithConcatenationOfAllWords/30_SubstringWithConcatenationOfAllWords.cpp
  30_SubstringWithConcatenationOfAllWords/30_SubstringWithConcatenationOfAllWords_t.cpp
  31_NextPermutation/31_NextPermutation.h
  31_NextPermutation/31_NextPermutation.cpp
  31_NextPermutation/31_NextPermutation_t.cpp
  32_LongestValidParentheses/32_LongestValidParentheses.h
  32_LongestValidParentheses/32_LongestValidParentheses.cpp
  32_LongestValidParentheses/32_LongestValidParentheses_t.cpp
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr.h
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr.cpp
  34_FirstAndLastPositionOfElemInSortedArr/34_FirstAndLastPositionOfElemInSortedArr_t.cpp
  36_ValidSudoku/36_ValidSudoku.h
  36_ValidSudoku/36_ValidSudoku.cpp
  36_ValidSudoku/36_ValidSudoku_t.cpp
  37_SudokuSolver/37_SudokuSolver.h
  37_SudokuSolver/37_SudokuSolver.cpp
  37_SudokuSolver/37_SudokuSolver_t.cpp
  39_CombinationSum/39_CombinationSum.h
  39_CombinationSum/39_CombinationSum.cpp
  39_CombinationSum/39_CombinationSum_t.cpp
  40_CombinationSumII/40_CombinationSumII.h
  40_CombinationSumII/40_CombinationSumII.cpp
  40_CombinationSumII/40_CombinationSumII_t.cpp
  41_FirstMissingPositive/41_FirstMissingPositive.h
  41_FirstMissingPositive/41_FirstMissingPositive.cpp
  41_FirstMissingPositive/41_FirstMissingPositive_t.cpp
  42_TrappingRainWater/42_TrappingRainWater.h
  42_TrappingRainWater/42_TrappingRainWater.cpp
  42_TrappingRainWater/42_TrappingRainWater_t.cpp
  44_WildcardMatching/44_WildcardMatching.h
  44_WildcardMatching/44_WildcardMatching.cpp
  44_WildcardMatching/44_WildcardMatching_V2.h
  44_WildcardMatching/44_WildcardMatching_V2.cpp
  44_WildcardMatching/44_WildcardMatching_t.cpp
  45_JumpGameII/45_JumpGameII.h
  45_JumpGameII/45_JumpGameII.cpp
  45_JumpGameII/45_JumpGameII_t.cpp
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
  50_PowXN/50_PowXN.h
  50_PowXN/50_PowXN.cpp
  50_PowXN/50_PowXN_t.cpp
  Catch2/src/catch2/catch_test_macros.hpp
)
target_link_libraries(leetcode_solutions Catch2::Catch2)
