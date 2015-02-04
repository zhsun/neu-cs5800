#include <utility>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Forward declare.
pair<bool,int> kth(vector<int>& A, int k, int low, int high);
int partition(vector<int>& A, int low, int high);

pair<bool,int> kth(vector<int>& A, int k) {
  return kth(A, k, 0, A.size()-1);
}

pair<bool,int> kth(vector<int>& A, int k, int low, int high) {
  if (k < 1 || low > high || high - low + 1 < k)
    return make_pair(false, 0);;
  int pivot_pos = partition(A, low, high);
  int pivot_rank = pivot_pos - low + 1;
  if (pivot_rank == k)
    return make_pair(true, A[pivot_pos]);
  if (pivot_rank > k) return kth(A, k, low, pivot_pos-1);
  return kth(A, k-pivot_rank, pivot_pos+1, high);
}

int partition(vector<int>& A, int low, int high) {
  int pivot = A[high];
  int i = low - 1;
  for (int cur = low; cur < high; cur++) {
    if (A[cur] < pivot) swap(A[++i], A[cur]);
  }
  swap(A[++i], A[high]);
  return i;
}

TEST(OrderStatsTest, First) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 1);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(1));
}

TEST(OrderStatsTest, Middle) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 5);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(5));
}

TEST(OrderStatsTest, Last) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 9);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(9));
}

TEST(OrderStatsTest, OutOfBound) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 10);
  EXPECT_THAT(r.first, Eq(false));
}
