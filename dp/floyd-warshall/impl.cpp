#include <limits>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

void FloydWarshall(const vector<vector<int>>& graph, vector<vector<int>>* dist) {
  int n = graph.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (graph[i][j] != -1) {
	(*dist)[i][j] = graph[i][j];
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	if ((*dist)[i][k] != -1 && (*dist)[k][j] != -1) {
	  int with_k = (*dist)[i][k] + (*dist)[k][j];
	  int without_k = (*dist)[i][j];
	  if (without_k == -1 || without_k > with_k) {
	    (*dist)[i][j] = with_k;
	  }
	}
      }
    }
  }
}


TEST(FloydWarshallTest, NoEdgeGraph) {
  // -1 means no edge.
  int n = 5;
  vector<vector<int>> graph(n, vector<int>(n, -1));
  vector<vector<int>> dist(n, vector<int>(n, -1));
  FloydWarshall(graph, &dist);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
	EXPECT_THAT(dist[i][j], Eq(-1));
      }
    }
  }
}

TEST(FloydWarshallTest, GeneralCase) {
  int n = 6;
  vector<vector<int>> graph(n, vector<int>(n, -1));
  graph[0][1] = graph[1][0] = 2;
  graph[0][3] = graph[3][0] = 5;
  graph[0][4] = graph[4][0] = 1;
  graph[1][3] = graph[3][1] = 1;
  graph[1][5] = graph[5][1] = 4;
  graph[2][3] = graph[3][2] = 3;
  graph[2][4] = graph[4][2] = 2;
  graph[3][5] = graph[5][3] = 1;
  vector<vector<int>> dist(n, vector<int>(n, -1));
  FloydWarshall(graph, &dist);
  EXPECT_THAT(dist[0][1], Eq(2));
  EXPECT_THAT(dist[4][5], Eq(5));
  EXPECT_THAT(dist[4][3], Eq(4));
  EXPECT_THAT(dist[2][1], Eq(4));
}
