#include <cmath>
#include "geometry/base.h"
#include "point_to_line.h"

double PointToLineDistance(const Point& l1, const Point& l2, const Point& p) {
  auto l1tol2 = l2 - l1;
  auto l1top = p - l1;
  // Make use of the fact cross product is the area of the
  // parallelogram. The sign represent direction, so we take absolute
  // values.
  double area = fabs(l1tol2 * l1top);
  return area / l1tol2.Norm();
}

double PointToSegmentDistance(const Point& s1, const Point& s2, const Point& p) {
  // Make use of the fact that dot product of A and B is
  // |A|*|B|*cos(Theta). So if it's positive, then Theta is in
  // (-pi/2,pi/2).
  if (((s2 - s1) ^ (p - s2)) > 0.0) {
    // s2 is the closest point.
    return (p - s2).Norm();
  }
  if (((s1 - s2) ^ (p - s1)) > 0.0) {
    // s1 is the closest point.
    return (p - s1).Norm();
  }
  // Closest point is on segment [s1,s2].
  return PointToLineDistance(s1, s2, p);
}
