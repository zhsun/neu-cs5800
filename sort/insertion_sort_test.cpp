#include <vector>

#include "gmock/gmock.h"
#include "sort/insertion_sort.hpp"

using namespace testing;

TEST(InsertionSortTest, NullList) {
  std::vector<int> arr;
  InsertionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(InsertionSortTest, SingleElementList) {
  std::vector<int> arr = {1};
  InsertionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(InsertionSortTest, GeneralCase) {
  std::vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  InsertionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));

  InsertionSort(arr.begin(), arr.end(), std::greater<int>());
  EXPECT_THAT(arr, ElementsAre(10,9,8,7,6,5,4,3,2,1));
}
