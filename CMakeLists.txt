cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("NEU-CS5800")

enable_testing()

# Set up complie error options.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
# Add compiler definition.
add_definitions(-std=c++0x)

# Add gmock.
set(GMOCK_HOME "${CMAKE_CURRENT_SOURCE_DIR}/lib/gmock-1.7.0")
add_subdirectory(${GMOCK_HOME} ${CMAKE_BINARY_DIR}/gmock)
include_directories(SYSTEM ${GMOCK_HOME}/gtest/include
                           ${GMOCK_HOME}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories
add_subdirectory("sort/count")