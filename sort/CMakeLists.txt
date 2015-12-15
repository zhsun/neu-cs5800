add_gmock_test(selection_sort_unittest selection_sort_test.cpp)
add_gmock_test(insertion_sort_unittest insertion_sort_test.cpp)
add_gmock_test(shell_sort_unittest shell_sort_test.cpp)
add_gmock_test(heap_sort_unittest heap_sort_test.cpp)
add_gmock_test(merge_sort_unittest merge_sort_test.cpp)
add_gmock_test(quick_sort_unittest quick_sort_test.cpp)
add_gmock_test(counting_sort_unittest counting_sort_test.cpp)
add_gmock_test(radix_sort_unittest radix_sort_test.cpp)
add_gmock_test(sort_unittest sort_test.cpp)

add_executable(sorting_benchmark benchmark.cc)

configure_file(datafile/random_int_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int_1m
  COPYONLY)
configure_file(datafile/random_int3d_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int3d_1m
  COPYONLY)
configure_file(datafile/random_float_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_float_1m
  COPYONLY)
