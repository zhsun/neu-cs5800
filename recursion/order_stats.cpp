#include "recursion/order_stats.h"

int partition(std::vector<int>& A, int low, int high) {
  int pivot = A[high];
  int i = low - 1;
  for (int cur = low; cur < high; cur++) {
    if (A[cur] < pivot) std::swap(A[++i], A[cur]);
  }
  std::swap(A[++i], A[high]);
  return i;
}

std::pair<bool,int> kth(std::vector<int>& A, int k, int low, int high) {
  if (k < 1 || low > high || high - low + 1 < k)
    return std::make_pair(false, 0);;
  int pivot_pos = partition(A, low, high);
  int pivot_rank = pivot_pos - low + 1;
  if (pivot_rank == k)
    return std::make_pair(true, A[pivot_pos]);
  if (pivot_rank > k) return kth(A, k, low, pivot_pos-1);
  return kth(A, k-pivot_rank, pivot_pos+1, high);
}

std::pair<bool,int> kth(std::vector<int>& A, int k) {
  return kth(A, k, 0, A.size()-1);
}
