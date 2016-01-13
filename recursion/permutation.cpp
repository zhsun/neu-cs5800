#include "permutation.h"

void PermutationRec(std::vector<int>& elems,
                    int i,
                    std::vector<std::vector<int>>& perms) {
  int n = elems.size();
  if (i == n) {
    // Hit the base case.
    perms.emplace_back(elems.begin(), elems.end());
    return;
  }
  for (int j = i; j < n; ++j) {
    std::swap(elems[i], elems[j]);
    PermutationRec(elems, i+1, perms);
    std::swap(elems[i], elems[j]);
  }
}

// Permutation takes an array of elems, and output all its
// permutations in *perms*.
void Permutation(const std::vector<int>& elems,
                 std::vector<std::vector<int>>& perms) {
  if (elems.empty()) {
    return;
  }
  std::vector<int> mutable_elems(elems);
  PermutationRec(mutable_elems, 0, perms);
}
