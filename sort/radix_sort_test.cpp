#include <vector>

#include "gmock/gmock.h"
#include "sort/radix_sort.hpp"

using namespace testing;

TEST(RadixSortTest, NullList) {
  std::vector<int> arr;
  RadixSort(arr.begin(), arr.end(), 1);
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(RadixSortTest, SingleElementList) {
  std::vector<int> arr = {1};
  RadixSort(arr.begin(), arr.end(), 1);
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(RadixSortTest, GeneralCase) {
  std::vector<int> arr = {465,321,474,355,123,
			  777,919,134,221,756};
  RadixSort(arr.begin(), arr.end(), 3);
  EXPECT_THAT(arr, ElementsAre(123,134,221,321,355,
                               465,474,756,777,919));
}
