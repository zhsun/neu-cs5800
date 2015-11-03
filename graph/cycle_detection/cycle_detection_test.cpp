#include "gmock/gmock.h"
#include "graph/graph.h"
#include "cycle_detection.h"

using namespace std;
using namespace testing;

TEST(HasCycleTest, GraphWithNoEdges) {
  AdjacencyList graph(5);
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, CycleGraph) {
  AdjacencyList graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  graph.AddEdge(4, 0);
  EXPECT_THAT(HasCycle(graph), Eq(true));
}

TEST(HasCycleTest, TreeGraph) {
  AdjacencyList graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 5);
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, DAG) {
  AdjacencyList graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 3);
  graph.AddEdge(2, 4);
  graph.AddEdge(4, 3);
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, GeneralCase) {
  AdjacencyList graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(0, 4);
  graph.AddEdge(2, 1);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 0);
  graph.AddEdge(4, 2);
  graph.AddEdge(4, 3);
  EXPECT_THAT(HasCycle(graph), Eq(true));
}
