#include "gmock/gmock.h"
#include "base.h"

using namespace std;
using namespace testing;

TEST(BaseTest, CrossProduct) {
  EXPECT_THAT(fabs(Point(1, 1) * Point(2, 0)), Eq(2));
  EXPECT_THAT(fabs(Point(1, 1) * Point(2, 2)), Eq(0));
  EXPECT_THAT(fabs(Point(0, 3) * Point(-3, 0)), Eq(9));
  EXPECT_THAT(fabs(Point(3, 0) * Point(-3, 0)), Eq(0));
}

TEST(BaseTest, IsClockwiseTo) {
  EXPECT_THAT(Point(1, 1).IsClockwiseTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(1, 0).IsClockwiseTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(1, -1).IsClockwiseTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(-1, 1).IsClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(-1, 0).IsClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(-1, -1).IsClockwiseTo(Point(0, 1)), Eq(false));
  // On the same line.
  EXPECT_THAT(Point(0, -1).IsClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(0, 1).IsClockwiseTo(Point(0, 1)), Eq(false));
}

TEST(BaseTest, IsCounterClockwiseTo) {
  EXPECT_THAT(Point(1, 1).IsCounterClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(1, 0).IsCounterClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(1, -1).IsCounterClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(-1, 1).IsCounterClockwiseTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(-1, 0).IsCounterClockwiseTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(-1, -1).IsCounterClockwiseTo(Point(0, 1)), Eq(true));
  // On the same line.
  EXPECT_THAT(Point(0, -1).IsCounterClockwiseTo(Point(0, 1)), Eq(false));
  EXPECT_THAT(Point(0, 1).IsCounterClockwiseTo(Point(0, 1)), Eq(false));
}

TEST(BaseTest, IsCollinearTo) {
  EXPECT_THAT(Point(0, -1).IsCollinearTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(0, 1).IsCollinearTo(Point(0, 1)), Eq(true));
  EXPECT_THAT(Point(0, 1).IsCollinearTo(Point(0.00001, 1)), Eq(false));
  EXPECT_THAT(Point(0, 1).IsCollinearTo(Point(-0.00001, 10)), Eq(false));
}

TEST(BaseTest, Norm) {
  EXPECT_THAT(Point(0, 1).Norm(), Eq(1));
  EXPECT_THAT(Point(0, -2).Norm(), Eq(2));
  EXPECT_THAT(Point(1, 1).Norm(), Eq(Point(-1, -1).Norm()));
}
