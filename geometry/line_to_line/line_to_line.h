#ifndef GEOMETRY_LINE_TO_LINE_H_
#define GEOMETRY_LINE_TO_LINE_H_

#include <tuple>
#include "geometry/base.h"

using LineFormula = std::tuple<double, double, double>;

// Returns a line Ax + By = C that passes through points u and v.
LineFormula ConvertLineRepresentation(const Point& u, const Point& v);

// Line 1 passes through u1 and u2, line 2 passes through v1 and
// v2. This function returns true if line 1 intersects with line 2,
// and populate *intersection* with the right value. Returns false
// when line 1 and line 2 are parallel.
bool LineIntersection(const Point& u1, const Point& u2,
                      const Point& v1, const Point& v2,
                      Point* intersection);

// Segment 1 is [u1, u2], and segment 2 is [v1, v2]. This function
// returns true if segment 1 intersects with segment 2, and populate
// *intersection* with the right value. Returns false otherwise.
bool SegmentIntersection(const Point& u1, const Point& u2,
                         const Point& v1, const Point& v2,
                         Point* intersection);

#endif  // GEOMETRY_LINE_TO_LINE_H_
