add_library(boggle boggle.cpp)

add_gmock_test(boggle_unittest boggle_test.cpp)
target_link_libraries(boggle_unittest boggle)