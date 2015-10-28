#include <algorithm>
#include <iterator>
#include <vector>
#include "combination.h"

void CombinationRec(const std::vector<int>& elems,
                    int i,
                    std::vector<std::vector<int>>& combs) {
  int n = elems.size();
  if (i == n) {
    // Hit base case.
    combs.push_back({});
    return;
  }
  // Subsets not containing ith elem.
  CombinationRec(elems, i+1, combs);
  std::vector<std::vector<int>> with_i;
  for (const std::vector<int>& c : combs) {
    with_i.push_back(c);
    with_i.back().push_back(elems[i]);
    // Keep elems in sorted order to make test easier.
    std::sort(with_i.back().begin(), with_i.back().end());
  }
  std::copy(with_i.begin(), with_i.end(), std::back_inserter(combs));
}

// Combination takes an array of elems and populate all its
// combinations in *combs*.
void Combination(const std::vector<int>& elems,
                 std::vector<std::vector<int>>& combs) {
  CombinationRec(elems, 0, combs);
}
