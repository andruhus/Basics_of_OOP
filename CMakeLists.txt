cmake_minimum_required(VERSION 3.15)
project(Homework)
set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 source/main.cpp)
add_executable(Google_Tests_run tests/mainTest.cpp)

add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(Google_Tests_run gtest gtest_main)
