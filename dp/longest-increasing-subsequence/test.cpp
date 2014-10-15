#include <algorithm>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Forward declare function to reconstruct dp solution.
void ConstructSolution(const vector<int>&, const vector<int>&, int, vector<int>*);

// LongestIncreasingSubsequence return the length of the longest
// increasing subsequence, and the *sub* paprameter with contain the
// solution.
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
	dp[j] = max(dp[j], dp[i] + 1);
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
  reverse(sub->begin(), sub->end());
}

TEST(LISTest, LengthZeroSequence) {
  vector<int> seq;
  vector<int> sub;
  EXPECT_THAT(LongestIncreasingSubsequence(seq, &sub), Eq(0));
  EXPECT_THAT(sub, IsEmpty());
}

TEST(LISTest, LengthOneSequence) {
  vector<int> seq = {1};
  vector<int> sub;
  EXPECT_THAT(LongestIncreasingSubsequence(seq, &sub), Eq(1));
  EXPECT_THAT(sub, ContainerEq(seq));
}

TEST(LISTest, SameElemSequence) {
  vector<int> seq = {3,3,3,3,3};
  vector<int> sub;
  EXPECT_THAT(LongestIncreasingSubsequence(seq, &sub), Eq(1));
  EXPECT_THAT(sub, ElementsAre(3));
}

TEST(LISTest, GeneralCase) {
  vector<int> seq = {5,2,8,6,3,6,9,6};
  vector<int> sub;
  EXPECT_THAT(LongestIncreasingSubsequence(seq, &sub), Eq(4));
  EXPECT_THAT(sub, ElementsAre(2,3,6,9));
}
