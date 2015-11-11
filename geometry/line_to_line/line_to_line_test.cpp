#include "gmock/gmock.h"
#include "geometry/base.h"
#include "line_to_line.h"

using namespace testing;

#include <iostream>

TEST(LineToLineTest, ConvertLineRepresentation) {
  double A, B, C;
  // Vertical line.
  std::tie(A, B, C) = ConvertLineRepresentation(Point(0, -1), Point(0, 1));
  EXPECT_THAT(A * 0.0 + B * 0.0, DoubleEq(C));
  EXPECT_THAT(A * 0.0 + B * (-2.0), DoubleEq(C));
  EXPECT_THAT(A * 0.0 + B * 2.0, DoubleEq(C));
  // Horizontal line.
  std::tie(A, B, C) = ConvertLineRepresentation(Point(-1, 0), Point(1, 0));
  EXPECT_THAT(A * 0.0 + B * 0.0, DoubleEq(C));
  EXPECT_THAT(A * (-2.0) + B * 0.0, DoubleEq(C));
  EXPECT_THAT(A * 2.0 + B * 0.0, DoubleEq(C));
  // General line.
  std::tie(A, B, C) = ConvertLineRepresentation(Point(0, 0), Point(1, 1));
  EXPECT_THAT(A * (-1.0) + B * (-1.0), DoubleEq(C));
  EXPECT_THAT(A * 0.0 + B * 0.0, DoubleEq(C));
  EXPECT_THAT(A * 1.0 + B * 1.0, DoubleEq(C));
}

TEST(LineToLineTest, LineIntersection) {
  Point p;
  // Parallel vertical lines.
  EXPECT_THAT(LineIntersection(Point(-1, -1), Point(-1, 1),
                               Point(1, -1), Point(1, 1), &p),
              Eq(false));
  // Parallel horizontal lines.
  EXPECT_THAT(LineIntersection(Point(-1, -1), Point(1, -1),
                               Point(-1, 1), Point(1, 1), &p),
              Eq(false));
  // General case.
  EXPECT_THAT(LineIntersection(Point(-1, -1), Point(1, 1),
                               Point(-1, 1), Point(1, -1), &p),
              Eq(true));
  EXPECT_THAT(p.x(), DoubleEq(0.0));
  EXPECT_THAT(p.y(), DoubleEq(0.0));
  EXPECT_THAT(LineIntersection(Point(0, 1), Point(2, 0),
                               Point(1, 0), Point(1, 1), &p),
              Eq(true));
  EXPECT_THAT(p.x(), DoubleEq(1.0));
  EXPECT_THAT(p.y(), DoubleEq(0.5));
}

TEST(LineToLineTest, SegmentIntersection) {
  Point p;
  // Parallel vertical segments.
  EXPECT_THAT(SegmentIntersection(Point(-1, -1), Point(-1, 1),
                                  Point(1, -1), Point(1, 1), &p),
              Eq(false));
  // Parallel horizontal segments.
  EXPECT_THAT(SegmentIntersection(Point(-1, -1), Point(1, -1),
                                  Point(-1, 1), Point(1, 1), &p),
              Eq(false));
  // Not parallel, but not intersecting.
  EXPECT_THAT(SegmentIntersection(Point(0, 0), Point(1, 1),
                                  Point(1.1, 0), Point(1.1, 1), &p),
              Eq(false));
  EXPECT_THAT(SegmentIntersection(Point(-0.001, -100), Point(0.001, 100),
                                  Point(5, -5), Point(5, 5), &p),
              Eq(false));
  // Intersect on end points.
  EXPECT_THAT(SegmentIntersection(Point(-1, 0), Point(0, 1),
                                  Point(1, 0), Point(0, 1), &p),
              Eq(true));
  EXPECT_THAT(p.x(), DoubleEq(0));
  EXPECT_THAT(p.y(), DoubleEq(1));
  EXPECT_THAT(SegmentIntersection(Point(0, 1), Point(2, 0),
                                  Point(1, 0), Point(1, 0.5), &p),
              Eq(true));
  EXPECT_THAT(p.x(), DoubleEq(1));
  EXPECT_THAT(p.y(), DoubleEq(0.5));
  // Intersect in the middle.
  EXPECT_THAT(SegmentIntersection(Point(0, 1), Point(2, 0),
                                  Point(0, 0), Point(2, 1), &p),
              Eq(true));
  EXPECT_THAT(p.x(), DoubleEq(1));
  EXPECT_THAT(p.y(), DoubleEq(0.5));
}
