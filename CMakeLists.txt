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
  1_TwoSum/1_TwoSum.h
  1_TwoSum/1_TwoSum.cpp
  1_TwoSum/1_TwoSum_t.cpp
  ListNode.cpp
  ListNode.h
  ListNode_t.cpp
  Catch2/src/catch2/catch_all.hpp
)
target_link_libraries(leetcode_solutions Catch2::Catch2)
