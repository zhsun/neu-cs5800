# Add gmock.
set(GMOCK_HOME "${CMAKE_SOURCE_DIR}/lib/gmock-1.7.0")
add_subdirectory(${GMOCK_HOME} ${CMAKE_BINARY_DIR}/gmock)
include_directories(SYSTEM ${GMOCK_HOME}/gtest/include
                           ${GMOCK_HOME}/include)
include_directories(${CMAKE_SOURCE_DIR})

#
# add_gmock_test(<target> <sources>...)
#
#  Adds a Google Mock based test executable, <target>, built from <sources> and
#  adds the test so that CTest will run it. Both the executable and the test
#  will be named <target>.
#
function(add_gmock_test target)
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} gmock_main)
    add_test(${target} ${target})
endfunction()
