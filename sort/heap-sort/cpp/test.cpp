#include <vector>
#include "gmock/gmock.h"

#include "data-structure/heap/cpp/heap_function.hpp"

using namespace std;
using namespace testing;

void Heapsort(vector<int>& arr) {
  heap_make(arr);
  for (int i = arr.size(); i > 0; i--) {
    heap_delete(arr, i);
  }
}

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
