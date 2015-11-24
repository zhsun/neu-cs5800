#include "closest_pair.h"
#include <algorithm>
#include <functional>
#include <limits>
#include <set>

using namespace std;

struct OrderByY {
  bool operator()(const Point& a, const Point& b) {
    return a.y() < b.y();
  }
};

double ClosestPair(
    const vector<Point>& points, Point& a, Point& b,
    function<double(const Point&, const Point&)> distance_fn) {
  if (points.size() < 2) return -1.0;
  vector<Point> sorted_points(points);
  // Sort by x dimension.
  sort(sorted_points.begin(), sorted_points.end(),
       [](const Point& a, const Point& b) { return a.x() < b.x(); });
  set<Point, OrderByY> considered_points = {sorted_points[0]};
  double distance = 1e10;  // As infinity.
  size_t left = 0;  // Index of left-most point should be considered.
  for (size_t i = 1; i < sorted_points.size(); ++i) {
    const Point& cur = sorted_points[i];
    // Limit points based on x dimension.
    while (left < i && cur.x() - sorted_points[left].x() > distance) {
      considered_points.erase(sorted_points[left++]);
    }
    // Limit points based on y dimension.
    Point boundary_point(cur.x(), cur.y()-distance);
    for (auto itr = considered_points.lower_bound(boundary_point);
         itr != considered_points.end() && itr->y() < cur.y()+distance;
         ++itr) {
      double new_distance = distance_fn(cur, *itr);
      if (new_distance < distance) {
        distance = new_distance;
        a = *itr, b = cur;
      }
    }
    considered_points.insert(cur);
  }
  return distance;
}
