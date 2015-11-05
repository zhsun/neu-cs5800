#include "gmock/gmock.h"
#include "longest_increasing_subsequence.h"

using namespace std;
using namespace testing;

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
