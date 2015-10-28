#include <list>
#include <tuple>
#include <vector>

using Vertex = size_t;
using Edge = std::tuple<Vertex, Vertex>;

class AdjacencyList final {
 public:
  explicit AdjacencyList(int num_vertices);
  ~AdjacencyList() = default;

  void AddNeighbors(Vertex u, std::list<Vertex> neighbors);
  const std::list<Vertex>& GetNeighbors(Vertex u) const;
  int NumVertices() const;

 private:
  std::vector<std::list<Vertex>> graph_;
};
