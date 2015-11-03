#include "gmock/gmock.h"
#include "graph/graph.h"
#include "bellman_ford.h"

using namespace std;
using namespace testing;

TEST(BellmanFordTest, NoEdgeGraph) {
  size_t n = 5;
  AdjacencyList graph(n);
  vector<double> distance;
  vector<Vertex> parent;
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(false));
  EXPECT_THAT(distance[0], Eq(0));
  for (size_t i = 1; i < n; ++i) {
    EXPECT_THAT(distance[i], Eq(std::numeric_limits<double>::max()));
  }
}

TEST(BellmanFordTest, DAG) {
  int n = 5;
  AdjacencyList graph(n);
  graph.AddEdgeWithCost(0, 1, 1);
  graph.AddEdgeWithCost(0, 2, 2);
  graph.AddEdgeWithCost(1, 3, 2);
  graph.AddEdgeWithCost(2, 3, 2);
  graph.AddEdgeWithCost(2, 4, 2);
  graph.AddEdgeWithCost(3, 4, 3);
  vector<double> distance;
  vector<Vertex> parent;
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(false));
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

TEST(BellmanFordTest, GeneralGraph) {
  int n = 6;
  AdjacencyList graph(n);
  graph.AddEdgeWithCost(1, 2, 1);
  graph.AddEdgeWithCost(1, 0, 4);
  graph.AddEdgeWithCost(1, 3, 5);
  graph.AddEdgeWithCost(2, 1, 3);
  graph.AddEdgeWithCost(2, 0, 2);
  graph.AddEdgeWithCost(2, 3, 3);
  graph.AddEdgeWithCost(3, 0, 1);
  graph.AddEdgeWithCost(4, 1, 2);
  graph.AddEdgeWithCost(4, 2, 4);
  vector<double> distance;
  vector<Vertex> parent;
  EXPECT_THAT(BellmanFord(graph, 4, &distance, &parent),
	      Eq(false));
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

TEST(BellmanFordTest, NegativeWeightedCycle) {
  int n = 5;
  AdjacencyList graph(n);
  graph.AddEdgeWithCost(0, 1, 3);
  graph.AddEdgeWithCost(0, 3, 2);
  graph.AddEdgeWithCost(1, 2, 4);
  graph.AddEdgeWithCost(1, 4, -5);
  graph.AddEdgeWithCost(2, 1, 1);
  graph.AddEdgeWithCost(3, 1, 2);
  graph.AddEdgeWithCost(3, 2, 1);
  graph.AddEdgeWithCost(4, 0, 1);
  graph.AddEdgeWithCost(4, 3, 3);
  vector<double> distance;
  vector<Vertex> parent;
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(true));
}
