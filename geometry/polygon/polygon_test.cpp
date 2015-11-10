#include "gmock/gmock.h"
#include "geometry/base.h"
#include "polygon.h"

using namespace testing;

TEST(PolygonTest, PolygonArea) {
  EXPECT_THAT(PolygonArea({Point(0, 0), Point(0, 1)}),
              DoubleEq(0.0));
  EXPECT_THAT(PolygonArea({Point(0, 0), Point(0, 1), Point(1, 0)}),
              DoubleEq(0.5));
  EXPECT_THAT(PolygonArea({Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0)}),
              DoubleEq(1.0));
  EXPECT_THAT(PolygonArea({Point(0, 1), Point(1, 0),
                           Point(0, -1), Point(-1, 0)}),
              DoubleEq(2.0));
  EXPECT_THAT(PolygonArea({Point(-1, 0), Point(0, 2), Point(1, 1),
                           Point(1, -1), Point(0, -2)}),
              DoubleEq(5.0));
  // 3 points on the same vertical line.
  EXPECT_THAT(PolygonArea({Point(-1, 0), Point(0, 1), Point(1, 1),
                           Point(1, 0), Point(1, -1), Point(0, -1)}),
              DoubleEq(3.0));
}
