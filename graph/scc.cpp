#include <vector>
#include "graph/graph.h"
#include "graph/topological_sort.h"
#include "graph/scc.h"

using std::vector;

AdjacencyList Reverse(const AdjacencyList& graph) {
  size_t n = graph.NumVertices();
  AdjacencyList rg(n);
  for (Vertex u = 0; u < n; ++u) {
    for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
      Vertex v;
      double ignored_cost;
      std::tie(v, ignored_cost) = neighbor;
      rg.AddEdge(v, u);
    }
  }
  return rg;
}

void Explore(const AdjacencyList& graph, Vertex u,
             vector<bool>& visited, vector<int>& cc) {
  visited[u] = true;
  for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
    Vertex v;
    double ignored_cost;
    std::tie(v, ignored_cost) = neighbor;
    if (!visited[v]) {
      cc[v] = cc[u];
      Explore(graph, v, visited, cc);
    }
  }
}

void StronglyConnectedComponents(const AdjacencyList& graph,
                                 std::vector<int>& cc) {
  cc.resize(graph.NumVertices());
  const AdjacencyList& reverse_graph = Reverse(graph);
  vector<Vertex> sorted;
  TopologicalSort(reverse_graph, sorted);
  vector<bool> visited(graph.NumVertices(), false);
  int cc_num = 1;
  for (Vertex u : sorted) {
    if (!visited[u]) {
      cc[u] = cc_num++;
      Explore(graph, u, visited, cc);
    }
  }
}
