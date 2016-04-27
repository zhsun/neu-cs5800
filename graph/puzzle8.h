#ifndef GRAPH_CYCLE_PUZZLE8_H_
#define GRAPH_CYCLE_PUZZLE8_H_

#include <ostream>
#include <string>
#include <utility>
#include <vector>

class Board {
 public:
  static const int kSize;
  static const int kEmpty;  // Number used to refer to empty cell.

  Board() = default;
  ~Board() = default;

  // Test if two boards have the same configuration.
  bool operator==(const Board& other) const;
  bool operator!=(const Board& other) const;

  // Less than operator. For std::set and std::map.
  bool operator<(const Board& other) const;

  // Convenient access method.
  const std::vector<int>& operator[](int i) const;

  // If (r1, c1) and (r2,c2) are neighbors of each other, and one of
  // them is empty, then swap two cells and return true; otherwise,
  // return false.
  bool Swap(int r1, int c1, int r2, int c2);

  std::pair<int, int> GetEmptyCellPosition() const;

  // Factory method to create a board.
  static Board MakeBoard(const std::vector<int>& values);

  friend std::ostream& operator<<(std::ostream& os, const Board& board);

 private:
  Board(const std::vector<int>& values);
  bool IsNeighbor(int r1, int c1, int r2, int c2) const;
  std::string ToString() const;

  std::vector<std::vector<int>> data_;
};

// Return the minimum number of steps needed. If unsolvable, return a
// negatvie value.
int SolverBfs(Board start, Board end);

#endif  // GRAPH_CYCLE_PUZZLE8_H_
