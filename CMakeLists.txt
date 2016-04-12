cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("NEU-CS5800")

enable_testing()
# Include gmock module.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(gmock)

# Set up complie error options.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -O2")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
# Add compiler definition.
add_definitions(-std=c++11)

# Add subdirectories
add_subdirectory("data_structure")
add_subdirectory("sort")
add_subdirectory("recursion")
add_subdirectory("dp")
add_subdirectory("graph")
add_subdirectory("geometry")
add_subdirectory("geometry/point_to_line")
add_subdirectory("geometry/line_to_line")
add_subdirectory("geometry/polygon")
add_subdirectory("geometry/closest_pair")
