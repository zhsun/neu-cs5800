#include "gmock/gmock.h"
#include "graph/boggle.h"

using namespace std;
using namespace testing;

class BoggleTest : public Test {
public:
  BoggleTest() {
    dict = {
      "apple", "bird", "and", "northeastern", "test"
    };
  }

  unordered_set<string> dict;
};

TEST_F(BoggleTest, NoWord) {
  vector<string> board = { "abcd",
                           "efgh",
                           "abcd",
                           "efgh"};
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(0));
  EXPECT_THAT(words.size(), Eq(0));
}

TEST_F(BoggleTest, SignleWord) {
  vector<string> board = { "appl",
                           "appe",
                           "cccc",
                           "ffff"};
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(1));
  EXPECT_THAT(words, ElementsAre("apple"));
}

TEST_F(BoggleTest, MutlipleWords) {
  vector<string> board = { "andy",
                           "pire",
                           "pbea",
                           "lexm"};
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(3));
  EXPECT_THAT(words, UnorderedElementsAre("and", "apple", "bird"));
}
