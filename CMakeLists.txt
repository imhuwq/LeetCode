cmake_minimum_required(VERSION 3.5)

project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)
include_directories(include)

add_executable(run_test UnitTest.cpp)
target_link_libraries(run_test gtest_main)
add_test(NAME run_test COMMAND run_test)

add_executable(run_newest_test NewestUnitTest.cpp)
target_link_libraries(run_newest_test gtest_main)
add_test(NAME run_newest_test COMMAND run_newest_test)