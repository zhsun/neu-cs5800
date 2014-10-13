#include <string>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Forward declare helper function.
char GetVal(const string&, int);

// EditDistance returns the minimum number of edits (insertion,
// deletion, and replacement) needed to change string a to string b.
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
      if (GetVal(a, r) == GetVal(b, c)) {
	dp[r][c] = dp[r-1][c-1];
      } else {
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

// GetVal is a helper function to value on 1-based index,
// e.g. GetVal(str, 1) will return the 1st char in str, and
// GetVal(str, 5) will return the 5th char in str.
char GetVal(const string& str, int one_based_index) {
  return str[one_based_index-1];
}

TEST(EditDistanceTest, BothEmpty) {
  EXPECT_THAT(EditDistance("", ""), Eq(0));
}

TEST(EditDistanceTest, OneEmpty) {
  string str = "xyz";
  EXPECT_THAT(EditDistance(str, ""), Eq(str.size()));
  EXPECT_THAT(EditDistance("", str), Eq(str.size()));
}

TEST(EditDistanceTest, GeneralCase) {
  EXPECT_THAT(EditDistance("exponential", "polynomial"), Eq(6));
}
