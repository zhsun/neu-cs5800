#ifndef GEOMETRY_CLOSEST_PAIR_H_
#define GEOMETRY_CLOSEST_PAIR_H_

#include "geometry/base.h"
#include <functional>
#include <vector>

// ClosesPair takes a list of 2D points, and return the distance
// between 2 closest points. It will populate *a* and *b* with which
// points are closest. If number of points given is less than 2, will
// return a negtive number.
//
// This function is implemented using line sweeping algorithm.
double ClosestPair(
    const std::vector<Point>& points, Point& a, Point& b,
    std::function<double(const Point&, const Point&)> distance_fn);

#endif  // GEOMETRY_CLOSEST_PAIR_H_
