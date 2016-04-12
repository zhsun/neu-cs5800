add_library(graph graph.cpp)
add_gmock_test(graph_unittest graph_test.cpp)
target_link_libraries(graph_unittest graph)

add_library(cycle_detection cycle_detection.cpp)
add_gmock_test(cycle_detection_unittest cycle_detection_test.cpp)
target_link_libraries(cycle_detection_unittest cycle_detection graph)

add_library(topological_sort topological_sort.cpp)
add_gmock_test(topological_sort_unittest topological_sort_test.cpp)
target_link_libraries(topological_sort_unittest topological_sort graph)

add_library(scc scc.cpp)
add_gmock_test(scc_unittest scc_test.cpp)
target_link_libraries(scc_unittest scc graph topological_sort)

add_library(boggle boggle.cpp)
add_gmock_test(boggle_unittest boggle_test.cpp)
target_link_libraries(boggle_unittest boggle)

add_library(dijkstra dijkstra.cpp)
add_gmock_test(dijkstra_unittest dijkstra_test.cpp)
target_link_libraries(dijkstra_unittest dijkstra graph)

add_library(bellman_ford bellman_ford.cpp)
add_gmock_test(bellman_ford_unittest bellman_ford_test.cpp)
target_link_libraries(bellman_ford_unittest bellman_ford graph)

add_library(floyd_warshall floyd_warshall.cpp)
add_gmock_test(floyd_warshall_unittest floyd_warshall_test.cpp)
target_link_libraries(floyd_warshall_unittest floyd_warshall graph)

add_library(prim prim.cpp)
add_gmock_test(prim_unittest prim_test.cpp)
target_link_libraries(prim_unittest prim graph)

add_library(kruskal kruskal.cpp)
add_gmock_test(kruskal_unittest kruskal_test.cpp)
target_link_libraries(kruskal_unittest kruskal graph disjoint_set)
