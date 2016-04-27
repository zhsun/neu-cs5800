#include "gmock/gmock.h"
#include "graph/puzzle8.h"

using namespace std;
using namespace testing;

TEST(Puzzle8Test, EqualOp) {
  Board b1 = Board::MakeBoard({0, 1, 2,
                               3, 4, 5,
                               6, 7, 8});
  Board b2 = Board::MakeBoard({1, 0, 2,
                               3, 4, 5,
                               6, 7, 8});
  Board b3 = Board::MakeBoard({1, 2, 3,
                               4, 5, 6,
                               7, 8, 0});
  Board b4 = Board::MakeBoard({0, 1, 2,
                               3, 4, 5,
                               6, 7, 8});
  EXPECT_THAT(b1, testing::Ne(b2));
  EXPECT_THAT(b1, testing::Eq(b4));
  EXPECT_THAT(b3, testing::Ne(b1));
  EXPECT_THAT(b3, testing::Ne(b2));
}

TEST(Puzzle8Test, LessThan) {
  Board b1 = Board::MakeBoard({0, 1, 2,
                               3, 4, 5,
                               6, 7, 8});
  Board b2 = Board::MakeBoard({1, 0, 2,
                               3, 4, 5,
                               6, 7, 8});
  EXPECT_THAT(b1 < b2, testing::Eq(true));
  EXPECT_THAT(b1 < b1, testing::Eq(false));
  EXPECT_THAT(b2 < b2, testing::Eq(false));
  EXPECT_THAT(b2 < b1, testing::Eq(false));
}

TEST(Puzzle8Test, Swap) {
  Board b = Board::MakeBoard({0, 1, 2,
                              3, 4, 5,
                              6, 7, 8});
  // Out of bound.
  EXPECT_THAT(b.Swap(-1, 0, 0, 0), testing::Eq(false));
  EXPECT_THAT(b.Swap(0, -1, 0, 0), testing::Eq(false));
  // Not neighbors.
  EXPECT_THAT(b.Swap(1, 0, 0, 1), testing::Eq(false));
  // Neighbors, but not with empty cell.
  EXPECT_THAT(b.Swap(1, 0, 1, 1), testing::Eq(false));
  // Swap 0 and 3.
  EXPECT_THAT(b.Swap(0, 0, 1, 0), testing::Eq(true));
  EXPECT_THAT(b[0][0], testing::Eq(3));
  EXPECT_THAT(b[1][0], testing::Eq(0));
}

TEST(Puzzle8Test, GetEmptyCellPosition) {
  Board b1 = Board::MakeBoard({1, 0, 2,
                               3, 4, 5,
                               6, 7, 8});
  EXPECT_THAT(b1.GetEmptyCellPosition(), testing::Eq(std::make_pair(0, 1)));
  Board b2 = Board::MakeBoard({1, 2, 3,
                               4, 5, 6,
                               7, 8, 0});
  EXPECT_THAT(b2.GetEmptyCellPosition(), testing::Eq(std::make_pair(2, 2)));
}

TEST(Puzzle8Test, SolverBfs) {
  Board start = Board::MakeBoard({0, 1, 2,
                                  3, 4, 5,
                                  6, 7, 8});
  EXPECT_THAT(SolverBfs(start, start), testing::Eq(0));
  Board end1 = Board::MakeBoard({3, 1, 2,
                                 0, 4, 5,
                                 6, 7, 8});
  EXPECT_THAT(SolverBfs(start, end1), testing::Eq(1));
  Board end2 = Board::MakeBoard({3, 1, 2,
                                 6, 4, 5,
                                 7, 8, 0});
  EXPECT_THAT(SolverBfs(start, end2), testing::Eq(4));
}

TEST(Puzzle8Test, SolverBfsNoSoln) {
  Board start = Board::MakeBoard({1, 2, 3,
                                  8, 0, 4,
                                  7, 6, 5});
  Board end = Board::MakeBoard({1, 2, 3,
                                4, 5, 6,
                                7, 8, 0});
  EXPECT_THAT(SolverBfs(start, end), testing::Lt(0));
}
