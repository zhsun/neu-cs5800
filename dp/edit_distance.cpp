#include <vector>
#include "edit_distance.h"

using std::string;
using std::vector;

// GetVal is a helper function to value on 1-based index,
// e.g. GetVal(str, 1) will return the 1st char in str, and
// GetVal(str, 5) will return the 5th char in str.
char GetVal(const string& str, int one_based_index) {
  return str[one_based_index-1];
}

int EditDistance(const string& a, const string& b) {
  int m = a.size();
  int n = b.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  for (int r = 1; r <= m; ++r) {
    dp[r][0] = r;
  }
  for (int c = 1; c <= n; ++c) {
    dp[0][c] = c;
  }
  for (int r = 1; r <= m; ++r) {
    for (int c = 1; c <= n; ++c) {
      // replace op.
      dp[r][c] = dp[r-1][c-1];
      if (GetVal(a, r) != GetVal(b, c)) {
        dp[r][c] = dp[r-1][c-1] + 1;
      }
      // delete op.
      if (dp[r-1][c] + 1 < dp[r][c]) {
        dp[r][c] = dp[r-1][c] + 1;
      }
      // insert op.
      if (dp[r][c-1] + 1 < dp[r][c]) {
        dp[r][c] = dp[r][c-1] + 1;
      }
    }
  }
  return dp[m][n];
}
