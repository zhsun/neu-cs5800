#include <cmath>
#include "gmock/gmock.h"
#include "geometry/base.h"
#include "point_to_line.h"

using namespace testing;

TEST(PointToLineTest, PointToLineDistance) {
  // Horizontal line.
  EXPECT_THAT(PointToLineDistance(Point(0, 0), Point(1, 0), Point(2, 1)),
              Eq(1));
  // Vertical line.
  EXPECT_THAT(PointToLineDistance(Point(0, 0), Point(0, 1), Point(1, 2)),
              Eq(1));
  // General line.
  EXPECT_THAT(PointToLineDistance(Point(-1, -1), Point(1, 1), Point(1, -1)),
              DoubleEq(sqrt(2)));
}

TEST(PointToLineTest, PointToSegmentDistance) {
  // Vertical segment.
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(1, 0)),
              Eq(1));
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(1, 1)),
              Eq(1));
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(-1, -1)),
              Eq(1));
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(0, 0)),
              Eq(0));
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(1, 2)),
              DoubleEq(sqrt(2)));
  EXPECT_THAT(PointToSegmentDistance(Point(0, -1), Point(0, 1), Point(-1, -2)),
              DoubleEq(sqrt(2)));
  // Horizontal segment.
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(1, 0)),
              Eq(0));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(-1, 0)),
              Eq(0));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(1, 1)),
              Eq(1));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(-1, 1)),
              Eq(1));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(2, 1)),
              DoubleEq(sqrt(2)));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, 0), Point(1, 0), Point(-2, 1)),
              DoubleEq(sqrt(2)));
  // General segment.
  EXPECT_THAT(PointToSegmentDistance(Point(-1, -1), Point(1, 1), Point(-1, 1)),
              DoubleEq(sqrt(2)));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, -1), Point(1, 1), Point(2, 0)),
              DoubleEq(sqrt(2)));
  EXPECT_THAT(PointToSegmentDistance(Point(-1, -1), Point(1, 1), Point(3, 0)),
              DoubleEq(sqrt(5)));
}
