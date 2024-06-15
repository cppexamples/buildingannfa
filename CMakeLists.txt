cmake_minimum_required(VERSION 3.20)
project(rl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(bnfa bnfa_main.cpp nfa.cpp ./digraph/digraph.cpp)
target_compile_options(bnfa PRIVATE -Ofast) #tail recursion

# Link runTests with what we want to test and the GTest and pthread library
#add_executable(ut gtest/tests.cpp)
#target_link_libraries(ut GTest::gtest_main)
