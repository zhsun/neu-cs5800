#include <vector>

#include "gmock/gmock.h"
#include "sort/sort.hpp"

using namespace testing;

TEST(SortTest, ThreeWayPartition) {
  std::vector<int> arr = {2,1,2,3,1,2,3,1,2,3,2};
  auto itrs = ThreeWayPartition(arr.begin(), arr.end(), std::less<int>());
  EXPECT_THAT(*itrs.first, Eq(2));
  EXPECT_THAT(*std::prev(itrs.first), Eq(1));
  EXPECT_THAT(*itrs.second, Eq(3));
  EXPECT_THAT(*std::prev(itrs.second), Eq(2));

  arr = {1,1,1,1,1};
  itrs = ThreeWayPartition(arr.begin(), arr.end(), std::less<int>());
  EXPECT_THAT(itrs.first, Eq(arr.begin()));
  EXPECT_THAT(itrs.second, Eq(arr.end()));
}

TEST(SortTest, NullList) {
  std::vector<int> arr;
  Sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(SortTest, SingleElementList) {
  std::vector<int> arr = {1};
  Sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(SortTest, GeneralCase) {
  std::vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  Sort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));

  Sort(arr.begin(), arr.end(), std::greater<int>());
  EXPECT_THAT(arr, ElementsAre(10,9,8,7,6,5,4,3,2,1));
}
