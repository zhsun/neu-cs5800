add_library(kruskal kruskal.cpp)

add_gmock_test(kruskal_unittest kruskal_test.cpp)
target_link_libraries(kruskal_unittest kruskal graph disjoint_set)