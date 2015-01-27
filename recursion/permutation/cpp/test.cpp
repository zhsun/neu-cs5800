#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Foward delcare.
void PermutationRec(vector<int>&, int i, vector<vector<int>>&);

// Permutation takes an array of elems, and output all its
// permutations in *perms*.
void Permutation(const vector<int>& elems, vector<vector<int>>& perms) {
  if (elems.empty()) {
    return;
  }
  vector<int> mutable_elems(elems);
  PermutationRec(mutable_elems, 0, perms);
}

void PermutationRec(vector<int>& elems,
		    int i,
		    vector<vector<int>>& perms) {
  int n = elems.size();
  if (i == n) {
    // Hit the base case.
    perms.emplace_back(elems.begin(), elems.end());
    return;
  }
  for (int j = i; j < n; ++j) {
    swap(elems[i], elems[j]);
    PermutationRec(elems, i+1, perms);
    swap(elems[i], elems[j]);
  }
}

TEST(PermutationTest, ZeroElem) {
  vector<vector<int>> perms;
  Permutation({}, perms);
  EXPECT_THAT(perms.empty(), Eq(true));
}

TEST(PermutationTest, SingleElem) {
  vector<vector<int>> perms;
  Permutation({1}, perms);
  vector<vector<int>> expected_perms = {{1}};
  EXPECT_THAT(perms, ContainerEq(expected_perms));
}

TEST(PermutationTest, GeneralCase) {
  vector<vector<int>> perms;
  Permutation({1,2,3}, perms);
  vector<vector<int>> expected_perms = {{1,2,3}, {1,3,2}, {2,1,3},
					{2,3,1}, {3,1,2}, {3,2,1}};
  EXPECT_THAT(perms, UnorderedElementsAreArray(expected_perms));
}
