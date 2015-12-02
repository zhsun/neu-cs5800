#include <functional>
#include <vector>

#include "gmock/gmock.h"
#include "sort/selection_sort.hpp"

using namespace testing;

TEST(SelectionSortTest, NullList) {
  std::vector<int> arr;
  SelectionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(SelectionSortTest, SingleElementList) {
  std::vector<int> arr = {1};
  SelectionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(SelectionSortTest, GeneralCase) {
  std::vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  SelectionSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));

  SelectionSort(arr.begin(), arr.end(), std::greater<int>());
  EXPECT_THAT(arr, ElementsAre(10,9,8,7,6,5,4,3,2,1));
}
