#include <limits>
#include "gmock/gmock.h"
#include "graph/graph.h"
#include "dijkstra.h"

using namespace std;
using namespace testing;

TEST(DijkstraTest, NoEdgeGraph) {
  AdjacencyList graph(5);
  vector<double> distance;
  vector<Vertex> parent;
  Dijkstra(graph, 0, &distance, &parent);
  EXPECT_THAT(distance[0], Eq(0));
  for (size_t i = 1; i < graph.NumVertices(); ++i) {
    EXPECT_THAT(distance[i], Eq(std::numeric_limits<double>::max()));
  }
}

TEST(DijkstraTest, DAG) {
  AdjacencyList graph(5);
  graph.AddEdgeWithCost(0, 1, 1.0);
  graph.AddEdgeWithCost(0, 2, 2.0);
  graph.AddEdgeWithCost(1, 3, 2.0);
  graph.AddEdgeWithCost(2, 3, 2.0);
  graph.AddEdgeWithCost(2, 4, 2.0);
  graph.AddEdgeWithCost(3, 4, 3.0);
  vector<double> distance;
  vector<Vertex> parent;
  Dijkstra(graph, 0, &distance, &parent);
  EXPECT_THAT(distance[0], Eq(0));
  EXPECT_THAT(distance[1], Eq(1));
  EXPECT_THAT(parent[1], Eq(0));
  EXPECT_THAT(distance[2], Eq(2));
  EXPECT_THAT(parent[2], Eq(0));
  EXPECT_THAT(distance[3], Eq(3));
  EXPECT_THAT(parent[3], Eq(1));
  EXPECT_THAT(distance[4], Eq(4));
  EXPECT_THAT(parent[4], Eq(2));
}

TEST(DijkstraTest, GeralGraph) {
  AdjacencyList graph(6);
  graph.AddEdgeWithCost(1, 2, 1.0);
  graph.AddEdgeWithCost(1, 0, 4.0);
  graph.AddEdgeWithCost(1, 3, 5.0);
  graph.AddEdgeWithCost(2, 1, 3.0);
  graph.AddEdgeWithCost(2, 0, 2.0);
  graph.AddEdgeWithCost(2, 3, 3.0);
  graph.AddEdgeWithCost(3, 0, 1.0);
  graph.AddEdgeWithCost(4, 1, 2.0);
  graph.AddEdgeWithCost(4, 2, 4.0);
  vector<double> distance;
  vector<Vertex> parent;
  Dijkstra(graph, 4, &distance, &parent);
  EXPECT_THAT(distance[4], Eq(0));
  EXPECT_THAT(distance[1], Eq(2));
  EXPECT_THAT(parent[1], Eq(4));
  EXPECT_THAT(distance[2], Eq(3));
  EXPECT_THAT(parent[2], Eq(1));
  EXPECT_THAT(distance[0], Eq(5));
  EXPECT_THAT(parent[0], Eq(2));
  EXPECT_THAT(distance[3], Eq(6));
  EXPECT_THAT(parent[3], Eq(2));
  EXPECT_THAT(distance[5], Eq(std::numeric_limits<double>::max()));
}
