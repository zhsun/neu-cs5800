#include <cassert>
#include <functional>
#include <limits>
#include "data_structure/priority_queue/priority_queue.hpp"
#include "graph/graph.h"
#include "graph/prim.h"

using std::vector;

// Order vertices in returned edges. Easier for testing.
Edge MakeEdge(Vertex u, Vertex v) {
  if (u < v) return Edge(u, v);
  return Edge(v, u);
}

double Prim(const AdjacencyList& graph, vector<Edge>* tree_edges) {
  assert(graph.NumVertices() > 0);
  double total_weight = 0.0;
  PriorityQueue<Vertex, double, std::greater<double>> q;
  for (Vertex u = 0; u < graph.NumVertices(); ++u) {
    q.Insert(u, std::numeric_limits<double>::max());
  }
  vector<double> distance(graph.NumVertices(),
                          std::numeric_limits<double>::max());
  vector<Vertex> parent(graph.NumVertices(),
                        std::numeric_limits<Vertex>::max());
  while (!q.IsEmpty()) {
    Vertex u = q.GetMax();
    q.Delete();
    if (parent[u] != std::numeric_limits<Vertex>::max()) {
      tree_edges->push_back(MakeEdge(parent[u], u));
      total_weight += distance[u];
    }
    for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
      Vertex v;
      double edge_cost;
      std::tie(v, edge_cost) = neighbor;
      if (q.Has(v) && edge_cost < distance[v]) {
        distance[v] = edge_cost;
        parent[v] = u;
        q.Update(v, distance[v]);
      }
    }
  }
  return total_weight;
}
