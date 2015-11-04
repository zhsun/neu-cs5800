add_library(dijkstra dijkstra.cpp)

add_gmock_test(dijkstra_unittest dijkstra_test.cpp)
target_link_libraries(dijkstra_unittest dijkstra graph)