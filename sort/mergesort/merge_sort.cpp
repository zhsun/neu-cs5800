#include <algorithm>
#include <vector>
#include "merge_sort.h"

void Merge(const std::vector<int>& arr1,
           const std::vector<int>& arr2,
           std::vector<int>* out) {
  int m = arr1.size();
  int n = arr2.size();
  out->resize(m + n);
  int i = 0, j = 0, k = 0;
  while (i < m && j < n) {
    if (arr1[i] < arr2[j]) {
      (*out)[k++] = arr1[i++];
    } else {
      (*out)[k++] = arr2[j++];
    }
  }
  while (i < m) {
    (*out)[k++] = arr1[i++];
  }
  while (j < n) {
    (*out)[k++] = arr2[j++];
  }
}

void Mergesort(const std::vector<int>& arr, std::vector<int>* out) {
  out->resize(arr.size());
  if (arr.size() < 2) {
    copy(arr.begin(), arr.end(), out->begin());
    return;
  }
  int middle = arr.size() / 2;
  std::vector<int> left(middle);
  copy(arr.begin(), arr.begin()+middle, left.begin());
  std::vector<int> right(arr.size() - middle);
  copy(arr.begin()+middle, arr.end(), right.begin());
  std::vector<int> sorted_left, sorted_right;
  Mergesort(left, &sorted_left);
  Mergesort(right, &sorted_right);
  Merge(sorted_left, sorted_right, out);
}
