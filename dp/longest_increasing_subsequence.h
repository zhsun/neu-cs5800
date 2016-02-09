#ifndef DP_LONGEST_INCREASING_SUBSEQUENCE_H_
#define DP_LONGEST_INCREASING_SUBSEQUENCE_H_

#include <vector>

// LongestIncreasingSubsequence return the length of the longest
// increasing subsequence, and the *sub* paprameter with contain the
// solution.
int LongestIncreasingSubsequence(const std::vector<int>& seq,
                                 std::vector<int>* sub);

#endif  // DP_LONGEST_INCREASING_SUBSEQUENCE_H_
