#include <algorithm>
#include <cmath>
#include "line_to_line.h"

using std::max;
using std::min;
using std::tie;

const double kEps = 1e-12;

LineFormula ConvertLineRepresentation(const Point& u, const Point& v) {
  double A = v.y() - u.y();
  double B = u.x() - v.x();
  double C = v.y() * u.x() - u.y() * v.x();
  return std::make_tuple(A, B, C);
}

bool LineIntersection(const Point& u1, const Point& u2,
                      const Point& v1, const Point& v2,
                      Point* intersection) {
  double A1, B1, C1;
  tie(A1, B1, C1) = ConvertLineRepresentation(u1, u2);
  double A2, B2, C2;
  tie(A2, B2, C2) = ConvertLineRepresentation(v1, v2);
  // Cramer's rule.
  double det = A1 * B2 - A2 * B1;
  if (fabs(det) < kEps) return false;
  *intersection = Point((C1 * B2 - C2 * B1) / det,
                        (A1 * C2 - A2 * C1) / det);
  return true;
}

bool SegmentIntersection(const Point& u1, const Point& u2,
                         const Point& v1, const Point& v2,
                         Point* intersection) {
  Point p;
  bool line_inter = LineIntersection(u1, u2, v1, v2, &p);
  if (line_inter == false) return false;
  bool ret =
      min(u1.x(), u2.x()) <= p.x() && p.x() <= max(u1.x(), u2.x()) &&
      min(u1.y(), u2.y()) <= p.y() && p.y() <= max(u1.y(), u2.y()) &&
      min(v1.x(), v2.x()) <= p.x() && p.x() <= max(v1.x(), v2.x()) &&
      min(v1.y(), v2.y()) <= p.y() && p.y() <= max(v1.y(), v2.y());
  if (ret) {
    *intersection = p;
  }
  return ret;
}
