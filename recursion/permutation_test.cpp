#include <vector>
#include "gmock/gmock.h"
#include "permutation.h"

using namespace std;
using namespace testing;

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
