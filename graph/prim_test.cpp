#include "gmock/gmock.h"
#include "graph/graph.h"
#include "graph/prim.h"

using namespace std;
using namespace testing;

void AddEdge(AdjacencyList& graph, Vertex u, Vertex v, double cost) {
  graph.AddEdgeWithCost(u, v, cost);
  graph.AddEdgeWithCost(v, u, cost);
}

TEST(PrimTest, CycleGraph) {
  AdjacencyList graph(5);
  AddEdge(graph, 0, 1, 1.0);
  AddEdge(graph, 1, 2, 2.0);
  AddEdge(graph, 2, 3, 3.0);
  AddEdge(graph, 3, 4, 4.0);
  AddEdge(graph, 4, 0, 5.0);

  vector<Edge> tree_edges;
  double weight = Prim(graph, &tree_edges);
  double expected_weight = 1.0 + 2.0 + 3.0 + 4.0;
  EXPECT_THAT(weight, Eq(expected_weight));
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(Edge(0, 1),
				   Edge(1, 2),
				   Edge(2, 3),
				   Edge(3, 4)));
}

TEST(PrimTest, TreeGraph) {
  AdjacencyList graph(6);
  AddEdge(graph, 0, 1, 1.0);
  AddEdge(graph, 0, 2, 2.0);
  AddEdge(graph, 1, 3, 3.0);
  AddEdge(graph, 1, 4, 4.0);
  AddEdge(graph, 2, 5, 5.0);

  vector<Edge> tree_edges;
  double weight = Prim(graph, &tree_edges);
  double expected_weight = 1.0 + 2.0 + 3.0 + 4.0 + 5.0;
  EXPECT_THAT(weight, Eq(expected_weight));
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(Edge(0, 1),
				   Edge(0, 2),
				   Edge(1, 3),
				   Edge(1, 4),
				   Edge(2, 5)));
}

TEST(PrimTest, GeneralGraph) {
  AdjacencyList graph(6);
  AddEdge(graph, 0, 1, 2.0);
  AddEdge(graph, 0, 2, 4.0);
  AddEdge(graph, 0, 4, 3.1);
  AddEdge(graph, 1, 2, 1.0);
  AddEdge(graph, 2, 4, 3.2);
  AddEdge(graph, 1, 3, 8.0);
  AddEdge(graph, 5, 1, 5.0);
  AddEdge(graph, 5, 2, 3.3);
  AddEdge(graph, 5, 4, 2.0);
  AddEdge(graph, 5, 3, 6.0);

  vector<Edge> tree_edges;
  double weight = Prim(graph, &tree_edges);
  double expected_weight = 2.0 + 3.1 + 1.0 + 2.0 + 6.0;
  EXPECT_THAT(weight, Eq(expected_weight));
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(Edge(0,1),
				   Edge(0,4),
				   Edge(1,2),
				   Edge(4,5),
				   Edge(3,5)));
}
