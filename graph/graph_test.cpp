#include "gmock/gmock.h"
#include "graph.h"

using namespace std;
using namespace testing;

TEST(Graph, AdjacencyList) {
  AdjacencyList graph(5);
  graph.AddNeighbors(1, {2, 3, 4});
  graph.AddNeighbors(3, {4});
  graph.AddNeighbors(3, {5});
  EXPECT_THAT(graph.GetNeighbors(0).empty(), Eq(true));
  EXPECT_THAT(graph.GetNeighbors(1), ElementsAre(2, 3, 4));
  EXPECT_THAT(graph.GetNeighbors(2).empty(), Eq(true));
  EXPECT_THAT(graph.GetNeighbors(3), ElementsAre(4, 5));
  EXPECT_THAT(graph.GetNeighbors(4).empty(), Eq(true));
}
