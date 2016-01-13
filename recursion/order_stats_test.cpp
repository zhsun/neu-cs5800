#include "gmock/gmock.h"
#include "order_stats.h"

using namespace std;
using namespace testing;

TEST(OrderStatsTest, First) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 1);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(1));
}

TEST(OrderStatsTest, Middle) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 5);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(5));
}

TEST(OrderStatsTest, Last) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 9);
  EXPECT_THAT(r.first, Eq(true));
  EXPECT_THAT(r.second, Eq(9));
}

TEST(OrderStatsTest, OutOfBound) {
  vector<int> A = {5,7,2,1,4,9,8,3,6};
  pair<bool,int> r = kth(A, 10);
  EXPECT_THAT(r.first, Eq(false));
}
