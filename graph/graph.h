#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <list>
#include <map>
#include <ostream>
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
  // Disable default ctor.
  AdjacencyList() = delete;

  void AddEdge(Vertex from, Vertex to);
  void AddEdgeWithCost(Vertex from, Vertex to, double cost);
  size_t NumVertices() const;

  NeighborList& GetNeighbors(Vertex u);
  const NeighborList& GetNeighbors(Vertex u) const;

  friend std::ostream& operator<<(std::ostream& os, const AdjacencyList& graph);

 private:
  std::vector<NeighborList> graph_;
};

#endif  // GRAPH_GRAPH_H_
