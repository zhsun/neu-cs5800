#include <cassert>
#include "graph.h"

AdjacencyList::AdjacencyList(int num_vertices) : graph_(num_vertices) {
}

size_t AdjacencyList::NumVertices() const {
  return graph_.size();
}

void AdjacencyList::AddEdge(Vertex from, Vertex to) {
  AddEdgeWithCost(from, to, 1.0);
}

void AdjacencyList::AddEdgeWithCost(Vertex from, Vertex to, double cost) {
  assert(from < NumVertices() && to < NumVertices());
  graph_[from].push_back(std::make_tuple(to, cost));
}

NeighborList& AdjacencyList::GetNeighbors(Vertex u) {
  assert(u < NumVertices());
  return graph_[u];
}

const NeighborList& AdjacencyList::GetNeighbors(Vertex u) const {
  assert(u < NumVertices());
  return graph_[u];
}
