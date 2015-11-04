cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("NEU-CS5800")

enable_testing()
# Include gmock module.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(gmock)

# Set up complie error options.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
# Add compiler definition.
add_definitions(-std=c++0x)

# Add subdirectories
add_subdirectory("recursion/combination")
add_subdirectory("recursion/permutation")
add_subdirectory("recursion/order_stats")
add_subdirectory("recursion/strassen")
add_subdirectory("sort/countingsort")
add_subdirectory("sort/heapsort")
add_subdirectory("sort/mergesort")
add_subdirectory("sort/quicksort")
add_subdirectory("sort/radixsort")
add_subdirectory("graph")
add_subdirectory("graph/cycle_detection")
add_subdirectory("graph/topological_sort")
add_subdirectory("graph/scc")
add_subdirectory("graph/boggle")
add_subdirectory("graph/dijkstra")
add_subdirectory("graph/bellman_ford")
add_subdirectory("graph/prim")
add_subdirectory("graph/kruskal")
add_subdirectory("data_structure/bst")
add_subdirectory("data_structure/priority_queue")
add_subdirectory("data_structure/disjoint_set")