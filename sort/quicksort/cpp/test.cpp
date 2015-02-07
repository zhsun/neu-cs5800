#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Forward declare.
int Partition(vector<int>& arr, int begin, int end);
void QuicksortRec(vector<int>& arr, int begin, int end);

// Quick sort algorithm on integer array.
void Quicksort(vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  int n = arr.size() - 1;
  QuicksortRec(arr, 0, n-1);
}

// Partition array, and return the index of pivot.
int Partition(vector<int>& arr, int begin, int end) {
  int pivot = arr[end];
  int i = begin-1;
  int cur = begin;
  while (cur < end) {
    if (arr[cur] < pivot) {
      swap(arr[++i], arr[cur]);
    }
    cur++;
  }
  swap(arr[++i], arr[cur]);
  return i;
}

// Sort elements in range arr[begin,...,end].
void QuicksortRec(vector<int>& arr, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot = Partition(arr, begin, end);
  QuicksortRec(arr, begin, pivot-1);
  QuicksortRec(arr, pivot+1, end);
}

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
