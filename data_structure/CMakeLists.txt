add_library(disjoint_set disjoint_set.cpp)
add_gmock_test(disjoint_set_unittest disjoint_set_test.cpp)
target_link_libraries(disjoint_set_unittest disjoint_set)

add_library(trie trie.cpp)
add_gmock_test(trie_unittest trie_test.cpp)
target_link_libraries(trie_unittest trie)

add_gmock_test(bst_unittest bst_test.cpp)
add_gmock_test(heap_unittest heap_test.cpp)
add_gmock_test(priority_queue_unittest priority_queue_test.cpp)
