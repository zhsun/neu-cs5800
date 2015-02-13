#include <list>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Forward declare DFS.
enum Color {
  WHITE,
  GRAY,
  BLACK,
};

bool Explore(const vector<list<int> >&, vector<Color>&, int);

// HasCycle makes use of DFS to detect cycles in graph.
bool HasCycle(const vector<list<int>>& graph) {
  int n = graph.size();
  vector<Color> color(n, WHITE);
  bool has_cycle = false;
  for (int i = 0; i < n; ++i) {
    if (color[i] == WHITE) {
      has_cycle |= Explore(graph, color, i);
    }
  }
  return has_cycle;
}

bool Explore(const vector<list<int>>& graph,
             vector<Color>& color,
             int node) {
  color[node] = GRAY;
  bool has_cycle = false;
  for (int neighbor : graph[node]) {
    if (color[neighbor] == GRAY) {
      has_cycle = true;
    } else if (color[neighbor] == WHITE) {
      has_cycle |= Explore(graph, color, neighbor);
    }
  }
  color[node] = BLACK;
  return has_cycle;
}

TEST(HasCycleTest, GraphWithNoEdges) {
  vector<list<int>> graph(5, list<int>());
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, CycleGraph) {
  vector<list<int>> graph = {{1},{2},{3},{4},{0}};
  EXPECT_THAT(HasCycle(graph), Eq(true));
}

TEST(HasCycleTest, TreeGraph) {
  vector<list<int>> graph = {{1,2},{3,4},{5},{},{},{}};
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, DAG) {
  vector<list<int>> graph = {{1,2},{3,4},{3,4},{},{3}};
  EXPECT_THAT(HasCycle(graph), Eq(false));
}

TEST(HasCycleTest, GeneralCase) {
  vector<list<int>> graph = {{1,2,4},{},{1,3},{0},{2,3}};
  EXPECT_THAT(HasCycle(graph), Eq(true));
}
