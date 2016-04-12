#include <algorithm>
#include <cassert>
#include "data_structure/disjoint_set.h"
#include "graph/graph.h"
#include "graph/kruskal.h"

using std::vector;

vector<EdgeWithCost> ExtractEdges(const AdjacencyList& graph) {
  vector<EdgeWithCost> edges;
  for (Vertex u = 0; u < graph.NumVertices(); ++u) {
    for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
      Vertex v;
      double cost;
      std::tie(v, cost) = neighbor;
      if (u < v) {
        edges.emplace_back(u, v, cost);
      }
    }
  }
  return edges;
}

double Kruskal(const AdjacencyList& graph, vector<Edge>* tree_edges) {
  assert(graph.NumVertices() > 0);
  vector<EdgeWithCost> edges = ExtractEdges(graph);
  std::sort(edges.begin(), edges.end(),
            [](const EdgeWithCost& a, const EdgeWithCost& b) {
              return std::get<2>(a) < std::get<2>(b);
            });
  double total_weight = 0.0;
  DisjointSet ds(graph.NumVertices());
  for (const EdgeWithCost& edge : edges) {
    Vertex u, v;
    double cost;
    std::tie(u, v, cost) = edge;
    if (ds.Find(u) != ds.Find(v)) {
      ds.Union(u, v);
      tree_edges->emplace_back(u, v);
      total_weight += cost;
    }
  }
  return total_weight;
}
