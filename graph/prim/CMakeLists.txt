add_library(prim prim.cpp)

add_gmock_test(prim_unittest prim_test.cpp)
target_link_libraries(prim_unittest prim graph)