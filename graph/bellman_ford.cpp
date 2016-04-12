#include <algorithm>
#include <cassert>
#include <limits>
#include "graph/bellman_ford.h"

// Return true if any distance is updated; false otherwise.
bool RelaxAllEdges(const AdjacencyList& graph,
                   std::vector<double>* distance,
                   std::vector<Vertex>* parent) {
  size_t n = graph.NumVertices();
  bool has_update = false;
  for (Vertex u = 0; u < n; ++u) {
    if ((*distance)[u] == std::numeric_limits<double>::max()) {
      continue;
    }
    const NeighborList& neighbors = graph.GetNeighbors(u);
    for (const Neighbor& neighbor : neighbors) {
      Vertex v;
      double edge_cost;
      std::tie(v, edge_cost) = neighbor;
      double dv = (*distance)[u] + edge_cost;
      if (dv < (*distance)[v]) {
        (*distance)[v] = dv;
        (*parent)[v] = u;
        has_update = true;
      }
    }
  }
  return has_update;
}

bool BellmanFord(const AdjacencyList& graph,
                 Vertex s,
                 std::vector<double>* distance,
                 std::vector<Vertex>* parent) {
  size_t n = graph.NumVertices();
  assert(n > 0);
  distance->resize(n, std::numeric_limits<double>::max());
  parent->resize(n, std::numeric_limits<Vertex>::max());

  (*distance)[s] = 0.0;
  for (Vertex i = 0; i < n - 1; ++i) {
    if (!RelaxAllEdges(graph, distance, parent)) {
      break;
    }
  }
  // Now detect if there is any negatively weighted cycle reachable
  // from s.
  return RelaxAllEdges(graph, distance, parent);
}
