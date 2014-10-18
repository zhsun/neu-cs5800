#include <algorithm>
#include <limits>
#include <list>
#include <tuple>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

// *graph* is represented in adjacency list format. tuple<int,double>
// means <neighbor id, distance>. *s* is the source vertex. *distance*
// will be the shortest distance from s to each vertex. *parent* holds
// the previous vertex id on the shortest path.
//
// Function will return true if there is a negatively weighted cycle,
// and false otherwise.
bool BellmanFord(const vector<list<tuple<int,int>>>& graph,
		 int s,
		 vector<int>* distance,
		 vector<int>* parent) {
  fill(distance->begin(), distance->end(), numeric_limits<int>::max());
  fill(parent->begin(), parent->end(), -1);
  (*distance)[s] = 0;
  int n = graph.size();
  for (int i = 0; i < n-1; ++i) {
    for (int u = 0; u < n; ++u) {
      if ((*distance)[u] == numeric_limits<int>::max()) {
	continue;
      }
      for (const tuple<int,int>& t : graph[u]) {
	int v = get<0>(t);
	int edge = get<1>(t);
	int dv = (*distance)[u] + edge;
	if (dv < (*distance)[v]) {
	  (*distance)[v] = dv;
	  (*parent)[v] = u;
	}
      }
    }
  }
  // Now detect if there is any negatively weighted cycle reachable
  // from s.
  for (int u = 0; u < n; ++u) {
    if ((*distance)[u] == numeric_limits<int>::max()) {
      continue;
    }
    for (const tuple<int,int>& t : graph[u]) {
      int v = get<0>(t);
      int edge = get<1>(t);
      int dv = (*distance)[u] + edge;
      if (dv < (*distance)[v]) {
	return true;
      }
    }
  }
  return false;
}

TEST(BellmanFordTest, NoEdgeGraph) {
  int n = 5;
  vector<list<tuple<int,int>>> graph(n);
  vector<int> distance(n);
  vector<int> parent(n);
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(false));
  EXPECT_THAT(distance[0], Eq(0));
  for (int i = 1; i < n; ++i) {
    EXPECT_THAT(distance[i], Eq(numeric_limits<int>::max()));
  }
}

TEST(BellmanFordTest, DAG) {
  int n = 5;
  vector<list<tuple<int,int>>> graph(n);
  graph[0] = {make_tuple(1,1), make_tuple(2,2)};
  graph[1] = {make_tuple(3,2)};
  graph[2] = {make_tuple(3,2), make_tuple(4,2)};
  graph[3] = {make_tuple(4,3)};
  vector<int> distance(n);
  vector<int> parent(n);
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(false));
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

TEST(BellmanFordTest, GeneralGraph) {
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
  EXPECT_THAT(BellmanFord(graph, 4, &distance, &parent),
	      Eq(false));
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

TEST(BellmanFordTest, NegativeWeightedCycle) {
  int n = 5;
  vector<list<tuple<int,int>>> graph(n);
  graph[0] = {make_tuple(1,3), make_tuple(3,2)};
  graph[1] = {make_tuple(2,4), make_tuple(4,-5)};
  graph[2] = {make_tuple(1,1)};
  graph[3] = {make_tuple(1,2), make_tuple(2,1)};
  graph[4] = {make_tuple(0,1), make_tuple(3,3)};
  vector<int> distance(n);
  vector<int> parent(n);
  EXPECT_THAT(BellmanFord(graph, 0, &distance, &parent),
	      Eq(true));
}
