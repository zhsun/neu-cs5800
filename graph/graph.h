#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <list>
#include <map>
#include <tuple>
#include <vector>

using Vertex = unsigned int;
using Neighbor = std::tuple<Vertex, double>;
using NeighborList = std::list<Neighbor>;

// AdjacencyList representation of directed graph.
class AdjacencyList final {
 public:
  explicit AdjacencyList(int num_vertices);
  ~AdjacencyList() = default;
  // Disable ctor, assign op.
  AdjacencyList() = delete;
  AdjacencyList(const AdjacencyList&) = delete;
  AdjacencyList& operator=(const AdjacencyList&) = delete;

  void AddEdge(Vertex from, Vertex to);
  void AddEdgeWithCost(Vertex from, Vertex to, double cost);
  size_t NumVertices() const;

  NeighborList& GetNeighbors(Vertex u);
  const NeighborList& GetNeighbors(Vertex u) const;

 private:
  std::vector<NeighborList> graph_;
};

#endif  // GRAPH_GRAPH_H_
