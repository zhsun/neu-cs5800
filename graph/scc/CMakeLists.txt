add_library(scc scc.cpp)

add_gmock_test(scc_unittest scc_test.cpp)
target_link_libraries(scc_unittest scc graph topological_sort)