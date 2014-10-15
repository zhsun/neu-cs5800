#include "data-structure/heap/heap.hpp"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

TEST(HeapTest, MaxHeapStartEmpty) {
  Heap<int> heap({});
  EXPECT_THAT(heap.IsEmpty(), Eq(true));

  int n = 10;
  for (int i = 1; i <= n; i++) {
    heap.Insert(i);
  }
  for (int i = n; i >= 1; --i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}

TEST(HeapTest, MinHeapStartEmpty) {
  Heap<int, greater<int>> heap({});
  EXPECT_THAT(heap.IsEmpty(), Eq(true));

  int n = 10;
  for (int i = 1; i <= n; i++) {
    heap.Insert(i);
  }
  for (int i = 1; i <= n; ++i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}

TEST(HeapTest, HeapStartWithList) {
  Heap<int> heap({1,3,2,6,4,5});
  EXPECT_THAT(heap.IsEmpty(), Eq(false));
  for (int i = 6; i >= 1; --i) {
    EXPECT_THAT(heap.GetMax(), Eq(i));
    heap.Delete();
  }
  EXPECT_THAT(heap.IsEmpty(), Eq(true));
}
