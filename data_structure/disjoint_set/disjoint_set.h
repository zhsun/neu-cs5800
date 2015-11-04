#ifndef DATA_STRUCTURE_DISJOINT_SET_H_
#define DATA_STRUCTURE_DISJOINT_SET_H_

#include <cstddef>
#include <vector>

class DisjointSet final {
 public:
  explicit DisjointSet(size_t n);
  ~DisjointSet() = default;
  DisjointSet() = delete;

  // Find with path compression.
  size_t Find(size_t x);
  // Union by rank.
  void Union(size_t x, size_t y);

 private:
  std::vector<size_t> parent_;
  std::vector<size_t> rank_;
};

#endif  // DATA_STRUCTURE_DISJOINT_SET_H_
