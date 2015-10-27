#include <vector>
#include "gmock/gmock.h"
#include "merge_sort.h"

using namespace std;
using namespace testing;

TEST(MergesortTest, SingleElementList) {
  vector<int> arr = {1};
  vector<int> out;
  Mergesort(arr, &out);
  EXPECT_THAT(out, ElementsAre(1));
}

TEST(MergesortTest, GeneralCase) {
  vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  vector<int> out;
  Mergesort(arr, &out);
  EXPECT_THAT(out, ElementsAre(1,2,3,4,5,6,7,8,9,10));
}
