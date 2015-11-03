#include <algorithm>
#include "gmock/gmock.h"
#include "graph/graph.h"
#include "topological_sort.h"

using namespace std;
using namespace testing;

template<typename Container>
typename Container::const_iterator
find(const Container& c,
     const typename Container::value_type& elem) {
  return std::find(std::begin(c), std::end(c), elem);
}

TEST(TopologicalSortTest, LineGraph) {
  AdjacencyList graph(5);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 4);
  vector<Vertex> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(sorted, ElementsAre(0,1,2,3,4));
}

TEST(TopologicalSortTest, TreeGraph) {
  AdjacencyList graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 4);
  graph.AddEdge(2, 5);
  vector<Vertex> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(find(sorted, 0), Lt(find(sorted, 1)));
  EXPECT_THAT(find(sorted, 0), Lt(find(sorted, 2)));
  EXPECT_THAT(find(sorted, 1), Lt(find(sorted, 3)));
  EXPECT_THAT(find(sorted, 1), Lt(find(sorted, 4)));
  EXPECT_THAT(find(sorted, 2), Lt(find(sorted, 5)));
}

TEST(TopologicalSortTest, GeneralDAG) {
  AdjacencyList graph(7);
  graph.AddEdge(1, 3);
  graph.AddEdge(1, 0);
  graph.AddEdge(2, 0);
  graph.AddEdge(4, 1);
  graph.AddEdge(4, 2);
  graph.AddEdge(5, 6);
  vector<Vertex> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(find(sorted, 1), Lt(find(sorted, 3)));
  EXPECT_THAT(find(sorted, 1), Lt(find(sorted, 0)));
  EXPECT_THAT(find(sorted, 2), Lt(find(sorted, 0)));
  EXPECT_THAT(find(sorted, 4), Lt(find(sorted, 1)));
  EXPECT_THAT(find(sorted, 4), Lt(find(sorted, 2)));
  EXPECT_THAT(find(sorted, 5), Lt(find(sorted, 6)));
}
