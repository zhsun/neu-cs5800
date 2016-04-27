#include <algorithm>
#include <cassert>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include "graph/puzzle8.h"

const int Board::kSize = 3;
const int Board::kEmpty = 0;

bool Board::operator==(const Board& other) const {
  for (int r = 0; r < kSize; ++r) {
    for (int c = 0; c < kSize; ++c) {
      if (data_[r][c] != other.data_[r][c]) {
        return false;
      }
    }
  }
  return true;
}

bool Board::operator!=(const Board& other) const {
  return !(*this == other);
}

bool Board::operator<(const Board& other) const {
  return ToString() < other.ToString();
}

const std::vector<int>& Board::operator[](int i) const {
  assert(i >= 0 && i < kSize);
  return data_[i];
}

bool Board::Swap(int r1, int c1, int r2, int c2) {
  // Check out of bound.
  if (r1 < 0 || r1 >= kSize) return false;
  if (c1 < 0 || c1 >= kSize) return false;
  if (r2 < 0 || r2 >= kSize) return false;
  if (c2 < 0 || c2 >= kSize) return false;
  // Check if are neighbor.
  if (!IsNeighbor(r1, c1, r2, c2)) return false;
  // Check if either is empty.
  if (data_[r1][c1] != kEmpty && data_[r2][c2] != kEmpty) return false;
  // Swap.
  std::swap(data_[r1][c1], data_[r2][c2]);
  return true;
}

bool Board::IsNeighbor(int r1, int c1, int r2, int c2) const {
  if (r1 == r2 && std::abs(c1 - c2) == 1) return true;
  if (c1 == c2 && std::abs(r1 - r2) == 1) return true;
  return false;
}

std::pair<int, int> Board::GetEmptyCellPosition() const {
  for (int r = 0; r < kSize; ++r) {
    for (int c = 0; c < kSize; ++c) {
      if (data_[r][c] == kEmpty) {
        return std::make_pair(r, c);
      }
    }
  }
  return std::make_pair(kSize, kSize);
}

std::string Board::ToString() const {
  std::string str;
  str.reserve(kSize * kSize);
  for (int r = 0; r < kSize; ++r) {
    for (int c = 0; c < kSize; ++c) {
      str.push_back(data_[r][c]);
    }
  }
  return str;
}

Board::Board(const std::vector<int>& values)
    : data_(kSize, std::vector<int>(kSize)) {
  std::copy(values.begin(), values.begin() + kSize,
            data_[0].begin());
  std::copy(values.begin() + kSize, values.begin() + 2 * kSize,
            data_[1].begin());
  std::copy(values.begin() + 2 * kSize, values.begin() + 3 * kSize,
            data_[2].begin());
}

Board Board::MakeBoard(const std::vector<int>& values) {
  assert(values.size() == kSize * kSize);
  return Board(values);
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
  for (int r = 0; r < Board::kSize; ++r) {
    for (int c = 0; c < Board::kSize; ++c) {
      if (board[r][c] == Board::kEmpty) {
        os << ' ';
      } else {
        os << board[r][c];
      }
      os << ' ';
    }
    os << std::endl;
  }
  return os;
}

void PrintSolution(Board start, Board end, std::map<Board, Board>& parent) {
  std::vector<Board> path;
  path.push_back(end);
  while (end != start) {
    Board p = parent[end];
    path.push_back(p);
    end = p;
  }
  for (auto itr = path.rbegin(); itr != path.rend(); ++itr) {
    if (itr != path.rbegin()) {
      std::cout << "  ||" << std::endl << "  \\/" << std::endl;
    }
    std::cout << *itr;
  }
  std::cout << std::endl;
}

int SolverBfs(Board start, Board end) {
  std::queue<Board> q;
  std::set<Board> visited;
  std::map<Board, Board> parent;
  std::map<Board, int> distance;
  q.push(start);
  visited.insert(start);
  distance[start] = 0;
  while (!q.empty()) {
    Board cur = q.front(); q.pop();
    if (cur == end) {
      PrintSolution(start, end, parent);
      return distance[cur];
    }
    auto pos = cur.GetEmptyCellPosition();
    int r = std::get<0>(pos);
    int c = std::get<1>(pos);
    for (int dr : {0, 1, 0, -1}) {
      for (int dc : {-1, 0, 1, 0}) {
        int nr = r + dr;
        int nc = c + dc;
        Board neighbor = cur;
        if (neighbor.Swap(r, c, nr, nc) &&
            visited.find(neighbor) == visited.end()) {
          // Found a new board configuration.
          q.push(neighbor);
          visited.insert(neighbor);
          parent[neighbor] = cur;
          distance[neighbor] = distance[cur] + 1;
        }
      }
    }
  }
  return -1;
}
