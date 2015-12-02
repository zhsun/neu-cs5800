add_gmock_test(selection_sort_unittest selection_sort_test.cpp)
add_gmock_test(insertion_sort_unittest insertion_sort_test.cpp)
add_gmock_test(heap_sort_unittest heap_sort_test.cpp)
add_gmock_test(merge_sort_unittest merge_sort_test.cpp)

add_executable(sorting_benchmark benchmark.cc)
target_link_libraries(sorting_benchmark quick_sort)

configure_file(datafile/random_int_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int_1m
  COPYONLY)
configure_file(datafile/random_int3d_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int3d_1m
  COPYONLY)
