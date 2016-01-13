#include <vector>
#include "gmock/gmock.h"
#include "combination.h"

using namespace std;
using namespace testing;

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
