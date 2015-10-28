#include <cassert>
#include "graph.h"

AdjacencyList::AdjacencyList(int num_vertices) : graph_(num_vertices) {
}

int AdjacencyList::NumVertices() const {
  return graph_.size();
}

void AdjacencyList::AddNeighbors(Vertex u, std::list<Vertex> neighbors) {
  assert(u < graph_.size());
  graph_[u].splice(graph_[u].end(), neighbors);
}

const std::list<Vertex>& AdjacencyList::GetNeighbors(Vertex u) const {
  assert(u < graph_.size());
  return graph_[u];
}
