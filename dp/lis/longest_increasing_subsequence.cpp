#include <algorithm>
#include "longest_increasing_subsequence.h"

using std::vector;

void ConstructSolution(const vector<int>& seq,
                       const vector<int>& dp,
                       int best,
                       vector<int>* sub) {
  int i = best;
  sub->push_back(seq[i]);
  while (dp[i] != 1) {
    for (int j = 0; j < i; ++j) {
      if (seq[j] < seq[i] && dp[j] + 1 == dp[i]) {
        i = j;
        sub->push_back(seq[i]);
        break;
      }
    }
    // Should not reach here.
  }
  std::reverse(sub->begin(), sub->end());
}

int LongestIncreasingSubsequence(const vector<int>& seq,
                                 vector<int>* sub) {
  if (seq.empty()) {
    return 0;
  }
  int n = seq.size();
  vector<int> dp(n, 1);
  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      if (seq[i] < seq[j]) {
        dp[j] = std::max(dp[j], dp[i] + 1);
      }
    }
  }

  int best = 0;
  for (int i = 1; i < n; ++i) {
    if (dp[best] < dp[i]) {
      best = i;
    }
  }
  ConstructSolution(seq, dp, best, sub);
  return dp[best];
}
