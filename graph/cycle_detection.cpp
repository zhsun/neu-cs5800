#include <vector>
#include "graph/cycle_detection.h"

using std::vector;

enum Color {
  WHITE,
  GRAY,
  BLACK,
};

bool Explore(const AdjacencyList& graph,
             vector<Color>& color,
             Vertex u) {
  color[u] = GRAY;
  bool has_cycle = false;
  for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
    Vertex v;
    double ignored_cost;
    std::tie(v, ignored_cost) = neighbor;
    if (color[v] == GRAY) {
      has_cycle = true;
    } else if (color[v] == WHITE) {
      has_cycle |= Explore(graph, color, v);
    }
  }
  color[u] = BLACK;
  return has_cycle;
}

bool HasCycle(const AdjacencyList& graph) {
  size_t n = graph.NumVertices();
  vector<Color> color(n, WHITE);
  bool has_cycle = false;
  for (size_t i = 0; i < n; ++i) {
    if (color[i] == WHITE) {
      has_cycle |= Explore(graph, color, i);
    }
  }
  return has_cycle;
}
