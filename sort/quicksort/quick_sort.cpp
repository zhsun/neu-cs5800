#include <algorithm>
#include <vector>
#include "quick_sort.h"

// Forward declare.
int Partition(std::vector<int>& arr, int begin, int end);
void QuicksortRec(std::vector<int>& arr, int begin, int end);

// Quick sort algorithm on integer array.
void Quicksort(std::vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  int n = arr.size() - 1;
  QuicksortRec(arr, 0, n-1);
}

// Partition array, and return the index of pivot.
int Partition(std::vector<int>& arr, int begin, int end) {
  int pivot = arr[end];
  int i = begin-1;
  int cur = begin;
  while (cur < end) {
    if (arr[cur] < pivot) {
      std::swap(arr[++i], arr[cur]);
    }
    cur++;
  }
  std::swap(arr[++i], arr[cur]);
  return i;
}

// Sort elements in range arr[begin,...,end].
void QuicksortRec(std::vector<int>& arr, int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot = Partition(arr, begin, end);
  QuicksortRec(arr, begin, pivot-1);
  QuicksortRec(arr, pivot+1, end);
}
