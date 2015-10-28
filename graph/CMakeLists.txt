add_library(graph graph.cpp)

add_gmock_test(graph_unittest graph_test.cpp)
target_link_libraries(graph_unittest graph)