#include <vector>

#include "gmock/gmock.h"
#include "sort/merge_sort.hpp"

using namespace testing;

TEST(MergeSortTest, NullList) {
  std::vector<int> arr;
  MergeSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(MergeSortTest, SingleElementList) {
  std::vector<int> arr = {1};
  MergeSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(MergeSortTest, GeneralCase) {
  std::vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  MergeSort(arr.begin(), arr.end());
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));

  MergeSort(arr.begin(), arr.end(), std::greater<int>());
  EXPECT_THAT(arr, ElementsAre(10,9,8,7,6,5,4,3,2,1));
}
