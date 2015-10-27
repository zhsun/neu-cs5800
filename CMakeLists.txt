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
add_subdirectory("sort/countingsort")
add_subdirectory("sort/heapsort")