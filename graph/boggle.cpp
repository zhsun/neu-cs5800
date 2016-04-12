#include "graph/boggle.h"

using std::string;
using std::unordered_set;
using std::vector;

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};
const int directions = 4;

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
  // Explore 4 eighbors.
  for (int i = 0; i < directions; ++i) {
    Explore(dict, board, row+dr[i], col+dc[i], visited, current, words);
  }
  current->pop_back();
  (*visited)[row][col] = false;
}

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
