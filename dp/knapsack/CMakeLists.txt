add_library(knapsack knapsack.cpp)

add_gmock_test(knapsack_unittest knapsack_test.cpp)
target_link_libraries(knapsack_unittest knapsack)