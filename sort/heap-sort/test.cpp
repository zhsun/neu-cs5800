#include <algorithm>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

void Heapsort(vector<int>* arr) {
  make_heap(arr->begin(), arr->end());
  int i = arr->size();
  while (i > 0) {
    pop_heap(arr->begin(), arr->begin() + i--);
  }
}

TEST(HeapsortTest, SingleElementArr) {
  vector<int> arr = {1};
  Heapsort(&arr);
  EXPECT_THAT(arr, ElementsAre(1));
}

TEST(HeapsortTest, GeneralCase) {
  vector<int> arr = {3,2,6,5,1,8,7,9,4,10};
  Heapsort(&arr);
  EXPECT_THAT(arr, ElementsAre(1,2,3,4,5,6,7,8,9,10));
}
