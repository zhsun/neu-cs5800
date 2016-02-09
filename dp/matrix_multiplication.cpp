#include <limits>
#include "matrix_multiplication.h"

using std::vector;

size_t MatrixMultiplication(const vector<size_t>& dims) {
  size_t n = dims.size() - 1;  // number of matrices
  // Have 1 extra col and row to make 1-based index easier.
  vector<vector<size_t>> dp(n+1, vector<size_t>(n+1, 0));
  for (size_t delta = 1; delta < n; ++delta) {
    for (size_t i = 1; i <= n - delta; ++i) {
      size_t j = i + delta;
      size_t best = std::numeric_limits<size_t>::max();
      for (size_t k = i; k < j; ++k) {
        size_t cur = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
        if (cur < best) {
          best = cur;
        }
      }
      dp[i][j] = best;
    }
  }
  return dp[1][n];
}
