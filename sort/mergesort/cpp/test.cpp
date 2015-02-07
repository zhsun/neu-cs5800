#include <algorithm>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

void Merge(const vector<int>& arr1,
	   const vector<int>& arr2,
	   vector<int>* out) {
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

void Mergesort(const vector<int>& arr, vector<int>* out) {
  out->resize(arr.size());
  if (arr.size() < 2) {
    copy(arr.begin(), arr.end(), out->begin());
    return;
  }
  int middle = arr.size() / 2;
  vector<int> left(middle);
  copy(arr.begin(), arr.begin()+middle, left.begin());
  vector<int> right(arr.size() - middle);
  copy(arr.begin()+middle, arr.end(), right.begin());
  vector<int> sorted_left, sorted_right;
  Mergesort(left, &sorted_left);
  Mergesort(right, &sorted_right);
  Merge(sorted_left, sorted_right, out);
}

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
