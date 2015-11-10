#ifndef GEOMETRY_POINT_TO_LINE_H_
#define GEOMETRY_POINT_TO_LINE_H_

#include "geometry/base.h"

// Line is represented by 2 points, l1 and l2. This function will
// return the distance of point p to this line.
double PointToLineDistance(const Point& l1, const Point& l2, const Point& p);

// Segment is represented by 2 points, s1 and s2. This function will
// return the distance of point p to this segment.
double PointToSegmentDistance(const Point& s1, const Point& s2, const Point& p);

#endif  // GEOMETRY_POINT_TO_LINE_H_
