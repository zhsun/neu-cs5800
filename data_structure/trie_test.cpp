#include "data_structure/trie.h"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(TrieTest, Insert) {
  Trie trie;
  EXPECT_THAT(trie.Insert("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Insert("apple"), testing::Eq(false));
  EXPECT_THAT(trie.Insert("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Insert("ape"), testing::Eq(true));
  EXPECT_THAT(trie.Insert("boy"), testing::Eq(true));
  EXPECT_THAT(trie.Insert("app"), testing::Eq(true));
}

TEST(TrieTest, Contain) {
  Trie trie;
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(false));

  trie.Insert("apple");
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("apply"), testing::Eq(false));
  EXPECT_THAT(trie.Contain("boy"), testing::Eq(false));
  EXPECT_THAT(trie.Contain("app"), testing::Eq(false));

  trie.Insert("apply");
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("boy"), testing::Eq(false));
  EXPECT_THAT(trie.Contain("app"), testing::Eq(false));

  trie.Insert("ape");
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("ape"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("boy"), testing::Eq(false));
  EXPECT_THAT(trie.Contain("app"), testing::Eq(false));

  trie.Insert("boy");
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("boy"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("app"), testing::Eq(false));

  trie.Insert("app");
  EXPECT_THAT(trie.Contain("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("boy"), testing::Eq(true));
  EXPECT_THAT(trie.Contain("app"), testing::Eq(true));
}

TEST(TrieTest, Delete) {
  Trie trie;
  EXPECT_THAT(trie.Delete("apple"), testing::Eq(false));
  trie.Insert("apple");
  EXPECT_THAT(trie.Delete("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Delete("apple"), testing::Eq(false));

  trie.Insert("apple");
  trie.Insert("apply");
  trie.Insert("app");
  EXPECT_THAT(trie.Delete("boy"), testing::Eq(false));
  EXPECT_THAT(trie.Delete("app"), testing::Eq(true));
  EXPECT_THAT(trie.Delete("apple"), testing::Eq(true));
  EXPECT_THAT(trie.Delete("app"), testing::Eq(false));
  EXPECT_THAT(trie.Delete("apply"), testing::Eq(true));
  EXPECT_THAT(trie.Delete("app"), testing::Eq(false));
  EXPECT_THAT(trie.Delete("apple"), testing::Eq(false));
  EXPECT_THAT(trie.Delete("apply"), testing::Eq(false));
}

TEST(TrieTest, Size) {
  Trie trie;
  EXPECT_THAT(trie.Size(), testing::Eq(0));
  trie.Insert("apple");
  EXPECT_THAT(trie.Size(), testing::Eq(1));
  trie.Insert("apply");
  EXPECT_THAT(trie.Size(), testing::Eq(2));
  trie.Insert("apple");
  EXPECT_THAT(trie.Size(), testing::Eq(2));
  trie.Insert("ape");
  EXPECT_THAT(trie.Size(), testing::Eq(3));
  trie.Insert("boy");
  EXPECT_THAT(trie.Size(), testing::Eq(4));
  trie.Insert("app");
  EXPECT_THAT(trie.Size(), testing::Eq(5));

  trie.Delete("app");
  EXPECT_THAT(trie.Size(), testing::Eq(4));
  trie.Delete("app");
  EXPECT_THAT(trie.Size(), testing::Eq(4));
  trie.Delete("ape");
  EXPECT_THAT(trie.Size(), testing::Eq(3));
  trie.Delete("apply");
  EXPECT_THAT(trie.Size(), testing::Eq(2));
  trie.Delete("apple");
  EXPECT_THAT(trie.Size(), testing::Eq(1));
  trie.Delete("boy");
  EXPECT_THAT(trie.Size(), testing::Eq(0));
  trie.Delete("boy");
  EXPECT_THAT(trie.Size(), testing::Eq(0));
}

TEST(TrieTest, WordCountWithPrefix) {
  Trie trie;
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(0));
  trie.Insert("apple");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(1));
  trie.Insert("apple");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(1));
  trie.Insert("apply");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(2));
  trie.Insert("ape");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(2));
  trie.Insert("boy");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(2));
  trie.Insert("app");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(3));
  EXPECT_THAT(trie.WordCountWithPrefix("ap"), testing::Eq(4));

  trie.Delete("apple");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(2));
  EXPECT_THAT(trie.WordCountWithPrefix("ap"), testing::Eq(3));
  trie.Delete("ape");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(2));
  EXPECT_THAT(trie.WordCountWithPrefix("ap"), testing::Eq(2));
  trie.Delete("boy");
  trie.Delete("app");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(1));
  EXPECT_THAT(trie.WordCountWithPrefix("ap"), testing::Eq(1));
  trie.Delete("apply");
  EXPECT_THAT(trie.WordCountWithPrefix("app"), testing::Eq(0));
  EXPECT_THAT(trie.WordCountWithPrefix("ap"), testing::Eq(0));
}

TEST(TrieTest, LongestPrefix) {
  Trie trie;
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq(""));
  trie.Insert("apple");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq(""));
  trie.Insert("boy");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq(""));
  trie.Insert("app");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq("app"));
  trie.Insert("apply");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq("apply"));
  trie.Delete("app");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq("apply"));
  trie.Delete("apply");
  EXPECT_THAT(trie.LongestPrefix("apply"), testing::Eq(""));
}
