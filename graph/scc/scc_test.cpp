#include "gmock/gmock.h"
#include "graph/graph.h"
#include "scc.h"

using namespace std;
using namespace testing;

TEST(SCCTest, NoEdgeGraph) {
  AdjacencyList graph(5);
  vector<int> cc;
  StronglyConnectedComponents(graph, cc);
  EXPECT_THAT(cc.size(), Eq(graph.NumVertices()));
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[4]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[1], Ne(cc[3]));
  EXPECT_THAT(cc[1], Ne(cc[4]));
  EXPECT_THAT(cc[2], Ne(cc[3]));
  EXPECT_THAT(cc[2], Ne(cc[4]));
  EXPECT_THAT(cc[3], Ne(cc[4]));
}

TEST(SCCTest, TreeGraph) {
  AdjacencyList graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 5);
  vector<int> cc;
  StronglyConnectedComponents(graph, cc);
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[4]));
  EXPECT_THAT(cc[0], Ne(cc[5]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[3], Ne(cc[4]));
}

TEST(SCCTest, GeneralGraph) {
  AdjacencyList graph(10);
  graph.AddEdge(1, 0);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 1);
  graph.AddEdge(2, 5);
  graph.AddEdge(3, 1);
  graph.AddEdge(4, 1);
  graph.AddEdge(5, 2);
  graph.AddEdge(6, 4);
  graph.AddEdge(6, 7);
  graph.AddEdge(7, 5);
  graph.AddEdge(7, 9);
  graph.AddEdge(8, 6);
  graph.AddEdge(9, 8);
  vector<int> cc;
  StronglyConnectedComponents(graph, cc);
  // 0 itself forms a cc.
  // 3 itself forms a cc.
  // 1 and 4 form a cc.
  EXPECT_THAT(cc[1], Eq(cc[4]));
  // 2 and 5 form a cc.
  EXPECT_THAT(cc[2], Eq(cc[5]));
  // 6, 7, 8, and 9 form a cc.
  EXPECT_THAT(cc[6], Eq(cc[7]));
  EXPECT_THAT(cc[6], Eq(cc[8]));
  EXPECT_THAT(cc[6], Eq(cc[9]));
  // Check different cc are numbered differently.
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[6]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[1], Ne(cc[3]));
  EXPECT_THAT(cc[1], Ne(cc[6]));
  EXPECT_THAT(cc[2], Ne(cc[3]));
  EXPECT_THAT(cc[2], Ne(cc[6]));
  EXPECT_THAT(cc[3], Ne(cc[6]));
}
