#include "gmock/gmock.h"
#include "floyd_warshall.h"

using namespace std;
using namespace testing;

TEST(FloydWarshallTest, NoEdgeGraph) {
  size_t n = 5;
  vector<vector<double>> graph(n, vector<double>(n, Inf));
  for (size_t i = 0; i < n; ++i) graph[i][i] = 0.0;
  vector<vector<double>> dist;
  FloydWarshall(graph, dist);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (i != j) {
	EXPECT_THAT(dist[i][j], Eq(Inf));
      }
    }
  }
}

TEST(FloydWarshallTest, GeneralCase) {
  size_t n = 6;
  vector<vector<double>> graph(n, vector<double>(n, Inf));
  for (size_t i = 0; i < n; ++i) graph[i][i] = 0.0;
  graph[0][1] = graph[1][0] = 2.0;
  graph[0][3] = graph[3][0] = 5.0;
  graph[0][4] = graph[4][0] = 1.0;
  graph[1][3] = graph[3][1] = 1.0;
  graph[1][5] = graph[5][1] = 4.0;
  graph[2][3] = graph[3][2] = 3.0;
  graph[2][4] = graph[4][2] = 2.0;
  graph[3][5] = graph[5][3] = 1.0;
  vector<vector<double>> dist;
  FloydWarshall(graph, dist);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      EXPECT_THAT(dist[i][j], Eq(dist[j][i]));
    }
  }
  EXPECT_THAT(dist[0][1], Eq(2.0));
  EXPECT_THAT(dist[0][2], Eq(3.0));
  EXPECT_THAT(dist[0][3], Eq(3.0));
  EXPECT_THAT(dist[0][4], Eq(1.0));
  EXPECT_THAT(dist[0][5], Eq(4.0));
  EXPECT_THAT(dist[1][2], Eq(4.0));
  EXPECT_THAT(dist[1][3], Eq(1.0));
  EXPECT_THAT(dist[1][4], Eq(3.0));
  EXPECT_THAT(dist[1][5], Eq(2.0));
  EXPECT_THAT(dist[2][3], Eq(3.0));
  EXPECT_THAT(dist[2][4], Eq(2.0));
  EXPECT_THAT(dist[2][5], Eq(4.0));
  EXPECT_THAT(dist[3][4], Eq(4.0));
  EXPECT_THAT(dist[3][5], Eq(1.0));
  EXPECT_THAT(dist[4][5], Eq(5.0));
}
