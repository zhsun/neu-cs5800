project(knapsack)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources-repeatable
  main.cpp
  impl-repeat.cpp)
add_executable(test-repeatable ${sources-repeatable})
target_link_libraries(test-repeatable gmock)
target_link_libraries(test-repeatable gtest)
target_link_libraries(test-repeatable pthread)

set(sources-nonrepeatable
  main.cpp
  impl-nonrepeat.cpp)
add_executable(test-nonrepeatable ${sources-nonrepeatable})
target_link_libraries(test-nonrepeatable gmock)
target_link_libraries(test-nonrepeatable gtest)
target_link_libraries(test-nonrepeatable pthread)
