#include <string>
#include <unordered_set>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Foward declare DFS.
void Explore(const unordered_set<string>& dict,
	     const vector<string>& board,
	     int row, int col,
	     vector<vector<bool>>* visited,
	     string* current,
	     unordered_set<string>* words);

// Boggle returns the number of words found in the *board*, and
// populate *words* accordingly.
int Boggle(const unordered_set<string>& dict,
	   const vector<string>& board,
	   unordered_set<string>* words) {
  int m = board.size();
  int n = board[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  string current;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      Explore(dict, board, i, j, &visited, &current, words);
    }
  }
  return words->size();
}

void Explore(const unordered_set<string>& dict,
	     const vector<string>& board,
	     int row, int col,
	     vector<vector<bool>>* visited,
	     string* current,
	     unordered_set<string>* words) {
  int m = board.size();
  int n = board[0].size();
  if (row < 0 || row >= m || 
      col < 0 || col >= n || 
      (*visited)[row][col]) {
    return;
  }
  (*visited)[row][col] = true;
  current->push_back(board[row][col]);
  if (dict.find(*current) != dict.end() &&
      words->find(*current) == words->end()) {
    words->insert(*current);
  }
  // Explore 8 eighbors.
  Explore(dict, board, row-1, col-1, visited, current, words);
  Explore(dict, board, row-1, col, visited, current, words);
  Explore(dict, board, row-1, col+1, visited, current, words);
  Explore(dict, board, row, col-1, visited, current, words);
  Explore(dict, board, row, col+1, visited, current, words);
  Explore(dict, board, row+1, col-1, visited, current, words);
  Explore(dict, board, row+1, col, visited, current, words);
  Explore(dict, board, row+1, col+1, visited, current, words);
  current->pop_back();
  (*visited)[row][col] = false;
}

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
  vector<string> board = {
    "abcd", "efgh", "abcd", "efgh"
  };
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(0));
  EXPECT_THAT(words.size(), Eq(0));
}

TEST_F(BoggleTest, SignleWord) {
  vector<string> board = {
    "appl", "appe", "cccc", "ffff"
  };
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(1));
  EXPECT_THAT(words, ElementsAre("apple"));
}

TEST_F(BoggleTest, MutlipleWords) {
  vector<string> board = {
    "and", "pir", "pbe", "xlx"
  };
  unordered_set<string> words;
  EXPECT_THAT(Boggle(dict, board, &words), Eq(3));
  EXPECT_THAT(words, UnorderedElementsAre("and", "apple", "bird"));
}
