#include <vector>
#include "gmock/gmock.h"
#include "quick_sort.h"

using namespace std;
using namespace testing;

TEST(QuicksortTest, SingleElementArr) {
  vector<int> arr = {1};
  Quicksort(arr);
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(QuicksortTest, GeneralCase) {
  vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  Quicksort(arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));
}
