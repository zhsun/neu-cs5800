#include <list>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// Foward declare DFS.
void Explore(const vector<list<int>>& graph,
             int node,
             vector<bool>& visited,
             vector<int>& sorted);

// TopologicalSort takes a DAG in adjacency list format, and output
// the topological order.
void TopologicalSort(const vector<list<int> >& graph,
                     vector<int>& sorted) {
  int n = graph.size();
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      Explore(graph, i, visited, sorted);
    }
  }
  // By the time DFS finished, nodes in *sorted* are in increasing
  // order in terms of finishing time. Reverse it to get topological
  // ordering.
  reverse(sorted.begin(), sorted.end());
}

void Explore(const vector<list<int>>& graph,
             int node,
             vector<bool>& visited,
             vector<int>& sorted) {
  visited[node] = true;
  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      Explore(graph, neighbor, visited, sorted);
    }
  }
  // When DFS is finished on this node, add itself to *sorted* list.
  sorted.push_back(node);
}

// Helper function to test ordering.
int FindIndex(const vector<int>& arr, int elem) {
  for (size_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == elem) {
      return i;
    }
  }
  return -1;
}

TEST(TopologicalSortTest, LineGraph) {
  vector<list<int>> graph = {{1},{2},{3},{4},{}};
  vector<int> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(sorted, ElementsAre(0,1,2,3,4));
}

TEST(TopologicalSortTest, TreeGraph) {
  vector<list<int>> graph = {{1,2},{3,4},{5},{},{},{}};
  vector<int> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(FindIndex(sorted, 0), Eq(0));
  EXPECT_THAT(FindIndex(sorted, 1), Lt(FindIndex(sorted, 3)));
  EXPECT_THAT(FindIndex(sorted, 1), Lt(FindIndex(sorted, 4)));
  EXPECT_THAT(FindIndex(sorted, 2), Lt(FindIndex(sorted, 5)));
}

TEST(TopologicalSortTest, GeneralDAG) {
  vector<list<int>> graph = {{},{3,0},{0},{},{1,2},{6},{}};
  vector<int> sorted;
  TopologicalSort(graph, sorted);
  EXPECT_THAT(FindIndex(sorted, 5), Lt(FindIndex(sorted, 6)));
  EXPECT_THAT(FindIndex(sorted, 4), Lt(FindIndex(sorted, 1)));
  EXPECT_THAT(FindIndex(sorted, 4), Lt(FindIndex(sorted, 2)));
  EXPECT_THAT(FindIndex(sorted, 1), Lt(FindIndex(sorted, 3)));
  EXPECT_THAT(FindIndex(sorted, 1), Lt(FindIndex(sorted, 0)));
  EXPECT_THAT(FindIndex(sorted, 2), Lt(FindIndex(sorted, 0)));
}
