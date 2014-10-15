#include <limits>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

int MatrixMultiplication(const vector<int>& dims) {
  int n = dims.size() - 1;  // number of matrices
  // Have 1 extra col and row to make 1-based index easier.
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
  for (int delta = 1; delta < n; ++delta) {
    for (int i = 1; i <= n - delta; ++i) {
      int j = i + delta;
      int best = numeric_limits<int>::max();
      for (int k = i; k < j; ++k) {
	int cur = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
	if (cur < best) {
	  best = cur;
	}
      }
      dp[i][j] = best;
    }
  }
  return dp[1][n];
}


TEST(MatrixMultiplicationTest, SingleMatrix) {
  EXPECT_THAT(MatrixMultiplication({3,4}), Eq(0));
}

TEST(MatrixMultiplicationTest, TwoMatrix) {
  EXPECT_THAT(MatrixMultiplication({3,4,5}), Eq(3 * 4 * 5));
}

TEST(MatrixMultiplicationTest, GeneralCase) {
  // A * ((B * C) * D) gives 120,200
  // (A * (B * C)) * D gives 60,200
  // (A * B) * (C * D) gives 7,000
  EXPECT_THAT(MatrixMultiplication({50,20,1,10,100}), Eq(7000));
}
