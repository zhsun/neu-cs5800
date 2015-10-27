#include <vector>

// KeyFn is a functor that maps T to int.
// 'k' specifies the range of key_fn(T). [0...k].
template<typename T, typename KeyFn>
void counting_sort(const std::vector<T>& A, std::vector<T>& B,
                   int k, KeyFn key_fn) {
  B.resize(A.size());
  std::vector<int> C(k+1, 0);
  for (const T& a : A) C[key_fn(a)]++;
  for (int i = 1; i <= k; i++) C[i] += C[i-1];
  for (int i = A.size()-1; i >= 0; i--) {
    int pos = C[key_fn(A[i])]-- - 1;
    B[pos] = A[i];
  }
}
