#include <vector>

class DisjointSet {
public:
  DisjointSet(int n) : parent_(n), rank_(n, 0) {
    for (int i = 0; i < n; ++i) {
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
  std::vector<int> parent_;
  std::vector<int> rank_;
};
