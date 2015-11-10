#include <cmath>
#include <cstddef>
#include "polygon.h"

double PolygonArea(const std::vector<Point>& points) {
  if (points.size() < 3) return 0.0;
  // Triangulate the polygon, and sum the area of each triangle using
  // cross product. The sign will take care of cancelation.
  auto base_point = points[0];
  double area = 0.0;
  for (size_t i = 1; i < points.size() - 1; ++i) {
    auto l1 = points[i] - base_point;
    auto l2 = points[i+1] - base_point;
    area += (l1 * l2);
  }
  return fabs(area / 2.0);
}
