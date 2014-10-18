#include <algorithm>
#include <limits>
#include <list>
#include <tuple>
#include <unordered_set>
#include <vector>
#include "data-structure/priority-queue/priority_queue.hpp"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// *graph* is represented in adjacency list format. tuple<int,int>
// means <neighbor id, distance>. *s* is the source vertex. *distance*
// will be the shorteast distance from s to each vertex (if no path
// exists, numeric_limits<int>::max() will be used). *parent* array
// holds the previous vertex id on the shortest path.
void Dijkstra(const vector<list<tuple<int,int>>>& graph,
	      int s,
	      vector<int>* distance,
	      vector<int>* parent) {
  fill(distance->begin(), distance->end(), numeric_limits<int>::max());
  fill(parent->begin(), parent->end(), -1);

  PriorityQueue<int,int,greater<int>> q;
  for (int i = 0; i < graph.size(); ++i) {
    q.Insert(i, numeric_limits<int>::max());
  }
  (*distance)[s] = 0;
  q.Update(s,0);
  unordered_set<int> S;
  while (S.size() != graph.size()) {
    int u = q.GetMax(); q.Delete();
    S.insert(u);
    if ((*distance)[u] != numeric_limits<int>::max()) {
      for (const tuple<int,int>& t : graph[u]) {
	int v = get<0>(t);
	int edge = get<1>(t);
	if ((*distance)[u] + edge < (*distance)[v]) {
	  (*distance)[v] = (*distance)[u] + edge;
	  (*parent)[v] = u;
	  q.Update(v, (*distance)[v]);
	}
      }
    }
  }
}

TEST(DijkstraTest, NoEdgeGraph) {
  int n = 5;
  vector<list<tuple<int,int>>> graph(n);
  vector<int> distance(n);
  vector<int> parent(n);
  Dijkstra(graph, 0, &distance, &parent);
  EXPECT_THAT(distance[0], Eq(0));
  for (int i = 1; i < n; ++i) {
    EXPECT_THAT(distance[i], Eq(numeric_limits<int>::max()));
  }
}

TEST(DijkstraTest, DAG) {
  int n = 5;
  vector<list<tuple<int,int>>> graph(n);
  graph[0] = {make_tuple(1,1), make_tuple(2,2)};
  graph[1] = {make_tuple(3,2)};
  graph[2] = {make_tuple(3,2), make_tuple(4,2)};
  graph[3] = {make_tuple(4,3)};
  vector<int> distance(n);
  vector<int> parent(n);
  Dijkstra(graph, 0, &distance, &parent);
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

TEST(DijkstraTest, GeralGraph) {
  int n = 6;
  vector<list<tuple<int,int>>> graph(n);
  graph[1] = {make_tuple(2,1),
	      make_tuple(0,4),
	      make_tuple(3,5)};
  graph[2] = {make_tuple(1,3),
	      make_tuple(0,2),
	      make_tuple(3,3)};
  graph[3] = {make_tuple(0,1)};
  graph[4] = {make_tuple(1,2),
	      make_tuple(2,4)};
  vector<int> distance(n);
  vector<int> parent(n);
  Dijkstra(graph, 4, &distance, &parent);
  EXPECT_THAT(distance[4], Eq(0));
  EXPECT_THAT(distance[1], Eq(2));
  EXPECT_THAT(parent[1], Eq(4));
  EXPECT_THAT(distance[2], Eq(3));
  EXPECT_THAT(parent[2], Eq(1));
  EXPECT_THAT(distance[0], Eq(5));
  EXPECT_THAT(parent[0], Eq(2));
  EXPECT_THAT(distance[3], Eq(6));
  EXPECT_THAT(parent[3], Eq(2));
  EXPECT_THAT(distance[5], Eq(numeric_limits<int>::max()));
}
