#include <vector>
#include "gmock/gmock.h"
#include "heap_sort.h"

using namespace std;
using namespace testing;

TEST(HeapsortTest, SingleElementArr) {
  vector<int> arr = {1};
  Heapsort(arr);
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(HeapsortTest, GeneralCase) {
  vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  Heapsort(arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));
}
