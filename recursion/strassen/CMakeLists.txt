add_library(strassen strassen.cpp)

add_gmock_test(strassen_unittest strassen_test.cpp)
target_link_libraries(strassen_unittest strassen)