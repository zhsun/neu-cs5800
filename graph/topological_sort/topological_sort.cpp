#include <algorithm>
#include "topological_sort.h"

using std::vector;

void Explore(const AdjacencyList& graph,
             Vertex u,
             vector<bool>& visited,
             vector<Vertex>& sorted) {
  visited[u] = true;
  for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
    Vertex v;
    double ignored_cost;
    std::tie(v, ignored_cost) = neighbor;
    if (!visited[v]) {
      Explore(graph, v, visited, sorted);
    }
  }
  // When DFS is finished on this node, add itself to *sorted* list.
  sorted.push_back(u);
}

void TopologicalSort(const AdjacencyList& graph,
                     vector<Vertex>& sorted) {
  size_t n = graph.NumVertices();
  vector<bool> visited(n, false);
  for (size_t i = 0; i < n; ++i) {
    if (!visited[i]) {
      Explore(graph, i, visited, sorted);
    }
  }
  // By the time DFS finished, nodes in *sorted* are in increasing
  // order in terms of finishing time. Reverse it to get topological
  // ordering.
  std::reverse(sorted.begin(), sorted.end());
}
