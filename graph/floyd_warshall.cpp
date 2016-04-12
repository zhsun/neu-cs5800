#include <cstddef>
#include <limits>
#include "graph/floyd_warshall.h"

using std::vector;

void FloydWarshall(const vector<vector<double>>& graph,
                   vector<vector<double>>& dist) {
  dist = graph;
  size_t n = graph.size();
  for (size_t k = 0; k < n; ++k) {
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (dist[i][k] != Inf && dist[k][j] != Inf) {
          dist[i][j] = std::min(dist[i][j],
                                dist[i][k] + dist[k][j]);
        }
      }
    }
  }
}
