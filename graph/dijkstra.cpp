#include <functional>
#include <limits>
#include "data_structure/priority_queue/priority_queue.hpp"
#include "graph/graph.h"
#include "graph/dijkstra.h"

void Dijkstra(const AdjacencyList& graph,
              Vertex s,
              std::vector<double>* distance,
              std::vector<Vertex>* parent) {
  size_t n = graph.NumVertices();
  distance->resize(n, std::numeric_limits<double>::max());
  parent->resize(n, std::numeric_limits<Vertex>::max());

  PriorityQueue<Vertex, double, std::greater<double>> q;
  for (Vertex u = 0; u < n; ++u) {
    q.Insert(u, std::numeric_limits<double>::max());
  }
  (*distance)[s] = 0;
  q.Update(s, 0);
  while (!q.IsEmpty()) {
    Vertex u = q.GetMax();
    q.Delete();
    if ((*distance)[u] != std::numeric_limits<double>::max()) {
      for (const Neighbor& neighbor : graph.GetNeighbors(u)) {
        Vertex v;
        double edge_cost;
        std::tie(v, edge_cost) = neighbor;
        if ((*distance)[u] + edge_cost < (*distance)[v]) {
          (*distance)[v] = (*distance)[u] + edge_cost;
          (*parent)[v] = u;
          q.Update(v, (*distance)[v]);
        }
      }
    }
  }
}
