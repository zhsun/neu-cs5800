#include <vector>

#include "gmock/gmock.h"
#include "sort/counting_sort.hpp"

using namespace testing;

TEST(CountingSortTest, NullList) {
  std::vector<int> arr;
  CountingSort(arr.begin(), arr.end(), [](int a) { return a; }, 0);
  EXPECT_THAT(arr, SizeIs(0));
}

TEST(CountingSortTest, SingleElementList) {
  std::vector<int> arr = {1};
  CountingSort(arr.begin(), arr.end(), [](int a) { return a; }, 1);
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(CountingSortTest, GeneralCase) {
  std::vector<int> arr = {3,1,2,5,3,1,5,2,4};
  CountingSort(arr.begin(), arr.end(), [](int a) { return a; }, 5);
  EXPECT_THAT(arr, ElementsAre(1,1,2,2,3,3,4,5,5));
}
