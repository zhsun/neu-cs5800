#ifndef GEOMETRY_POLYGON_H_
#define GEOMETRY_POLYGON_H_

#include <vector>
#include "geometry/base.h"

// Polygon is represented by a list of points. These points should be
// in order, either clockwise or counter clockwise.
double PolygonArea(const std::vector<Point>& points);

#endif  // GEOMETRY_POLYGON_H_
