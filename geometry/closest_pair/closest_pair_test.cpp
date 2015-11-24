#include "gmock/gmock.h"
#include "geometry/base.h"
#include "closest_pair.h"
#include <vector>

using std::vector;
using namespace testing;

TEST(ClosestPairTest, InvalidCase) {
  Point a, b;
  EXPECT_THAT(ClosestPair({}, a, b, EuclideanDistance), Le(0.0));
  EXPECT_THAT(ClosestPair({Point(0, 0)}, a, b, EuclideanDistance), Le(0.0));
}

TEST(ClosestPairTest, GeneralCase) {
  Point expected_a = Point(1, 0);
  Point expected_b = Point(1.2, 0.6);
  const vector<Point> points = {
    Point(-11, -13), Point(13, 11), Point(-101, 1), Point(-50, 21),
    Point(0, 1), Point(2.5, 89), Point(3, -41), Point(0, 22),
    Point(7, 8), Point(8, 11), Point(9, 1), Point(12, 11),
    expected_a, expected_b
  };
  Point a, b;
  EXPECT_THAT(ClosestPair(points, a, b, EuclideanDistance),
              DoubleEq(EuclideanDistance(expected_a, expected_b)));
  EXPECT_THAT(vector<Point>({a, b}),
              UnorderedElementsAre(expected_a, expected_b));
}
