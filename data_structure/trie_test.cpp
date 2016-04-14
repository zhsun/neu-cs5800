#include "data_structure/trie.hpp"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(TrieTest, Insert) {
  Trie<int, 0> trie;
  EXPECT_THAT(trie.Insert("apple", 1), testing::Eq(true));
  EXPECT_THAT(trie.Insert("apple", 2), testing::Eq(false));
  EXPECT_THAT(trie.Insert("apply", 3), testing::Eq(true));
  EXPECT_THAT(trie.Insert("ape", 4), testing::Eq(true));
  EXPECT_THAT(trie.Insert("boy", 5), testing::Eq(true));
  EXPECT_THAT(trie.Insert("app", 6), testing::Eq(false));
}
