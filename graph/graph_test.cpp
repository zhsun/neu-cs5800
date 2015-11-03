#include "gmock/gmock.h"
#include "graph.h"

using namespace std;
using namespace testing;

TEST(Graph, AdjacencyList) {
  AdjacencyList graph(5);
  graph.AddEdge(1, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(3, 4);
  graph.AddEdge(3, 2);
  EXPECT_THAT(graph.NumVertices(), Eq(5));
  auto neighbors = graph.GetNeighbors(1);
  EXPECT_THAT(neighbors.size(), Eq(3));
  neighbors = graph.GetNeighbors(2);
  EXPECT_THAT(neighbors.size(), Eq(0));
  const auto const_neighbors = graph.GetNeighbors(3);
  EXPECT_THAT(const_neighbors.size(), Eq(2));
  for (auto u : const_neighbors) {
    Vertex v;
    double cost;
    std::tie(v, cost) = u;
    EXPECT_THAT(cost, Eq(1.0));
  }
}
