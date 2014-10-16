#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

class DisjointSet {
public:
  DisjointSet(size_t n) : parent_(n), rank_(n, 0) {
    for (size_t i = 0; i < n; ++i) {
      parent_[i] = i;
    }
  }

  int Find(int x) {
    // Find root.
    int r = x;
    while (parent_[r] != r) {
      r = parent_[r];
    }
    // Path compression.
    while (parent_[x] != x) {
      int old_parent = parent_[x];
      parent_[x] = r;
      x = old_parent;
    }
    return r;
  }

  void Union(int x, int y) {
    // Union by rank.
    int rx = Find(x);
    int ry = Find(y);
    if (rank_[rx] < rank_[ry]) {
      parent_[rx] = ry;
    } else if (rank_[rx] > rank_[ry]) {
      parent_[ry] = rx;
    } else {
      parent_[ry] = rx;
      ++rank_[rx];
    }
  }

private:
  vector<int> parent_;
  vector<int> rank_;
};


TEST(DisjointSetTest, GeneralCase) {
  DisjointSet ds(5);
  EXPECT_THAT(ds.Find(0), Ne(ds.Find(3)));

  ds.Union(1,2);
  EXPECT_THAT(ds.Find(1), Eq(ds.Find(2)));
  EXPECT_THAT(ds.Find(1), Ne(ds.Find(3)));

  ds.Union(3,4);
  EXPECT_THAT(ds.Find(3), Eq(ds.Find(4)));
  EXPECT_THAT(ds.Find(3), Ne(ds.Find(1)));

  ds.Union(2,4);
  EXPECT_THAT(ds.Find(1), Eq(ds.Find(2)));
  EXPECT_THAT(ds.Find(2), Eq(ds.Find(3)));
  EXPECT_THAT(ds.Find(3), Eq(ds.Find(4)));
  EXPECT_THAT(ds.Find(0), Ne(ds.Find(1)));
}
