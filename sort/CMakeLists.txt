add_executable(sorting_benchmark benchmark.cc)
target_link_libraries(sorting_benchmark 
  quick_sort heap_sort)

configure_file(datafile/random_int_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int_1m
  COPYONLY)
configure_file(datafile/random_int3d_1m 
  ${CMAKE_CURRENT_BINARY_DIR}/datafile/random_int3d_1m
  COPYONLY)
