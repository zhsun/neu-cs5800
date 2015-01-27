#include <iterator>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Foward declare.
void CombinationRec(const vector<int>&, int, vector<vector<int>>&);

// Combination takes an array of elems and populate all its
// combinations in *combs*.
void Combination(const vector<int>& elems, vector<vector<int>>& combs) {
  CombinationRec(elems, 0, combs);
}

void CombinationRec(const vector<int>& elems,
		    int i,
		    vector<vector<int>>& combs) {
  int n = elems.size();
  if (i == n) {
    // Hit base case.
    combs.push_back({});
    return;
  }
  // Subsets not containing ith elem.
  CombinationRec(elems, i+1, combs);
  vector<vector<int>> with_i;
  for (const vector<int>& c : combs) {
    with_i.push_back(c);
    with_i.back().push_back(elems[i]);
    // Keep elems in sorted order to make test easier.
    sort(with_i.back().begin(), with_i.back().end());
  }
  copy(with_i.begin(), with_i.end(), back_inserter(combs));
}

TEST(CombinationTest, ZeroElem) {
  vector<vector<int>> combs;
  Combination({}, combs);
  vector<vector<int>> expected_combs = {{}};
  EXPECT_THAT(combs, UnorderedElementsAreArray(expected_combs));
}

TEST(CombinationTest, SingleElem) {
  vector<vector<int>> combs;
  Combination({1}, combs);
  vector<vector<int>> expected_combs = {{}, {1}};
  EXPECT_THAT(combs, UnorderedElementsAreArray(expected_combs));
}

TEST(CombinationTest, GeneralCase) {
  vector<vector<int>> combs;
  Combination({1,2,3}, combs);
  vector<vector<int>> expected_combs = {{}, {1}, {2}, {3},
  					{1,2}, {2,3}, {1,3},
  					{1,2,3}};
  EXPECT_THAT(combs, UnorderedElementsAreArray(expected_combs));
}
