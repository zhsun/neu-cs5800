#include <cassert>
#include "disjoint_set.h"

DisjointSet::DisjointSet(size_t n) : parent_(n), rank_(n, 1) {
  for (size_t i = 0; i < n; ++i) {
    parent_[i] = i;
  }
}

size_t DisjointSet::Find(size_t x) {
  assert(x < parent_.size());
  if (parent_[x] != x) {
    parent_[x] = Find(parent_[x]);
  }
  return parent_[x];
}

void DisjointSet::Union(size_t x, size_t y) {
  size_t rx = Find(x);
  size_t ry = Find(y);
  if (rank_[rx] < rank_[ry]) {
    parent_[rx] = ry;
  } else if (rank_[rx] > rank_[ry]) {
    parent_[ry] = rx;
  } else {
    parent_[ry] = rx;
    ++rank_[rx];
  }
}
