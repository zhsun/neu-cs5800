#include <list>
#include <unordered_set>
#include <vector>
#include "data-structure/priority-queue/priority_queue.hpp"
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

void Prim(const vector<list<tuple<int,double>>>& graph,
	  vector<tuple<int,int>>* tree_edges) {
  int n = graph.size();
  vector<int> parent(n, -1);
  vector<double> priority(n, numeric_limits<double>::max());
  PriorityQueue<int,double,greater<double>> q;
  for (int i = 0; i < n; ++i) {
    q.Insert(i, numeric_limits<double>::max());
  }
  unordered_set<int> S;
  while (S.size() != n) {
    int u = q.GetMax(); q.Delete();
    S.insert(u);
    for (const tuple<int,double>& t : graph[u]) {
      int v = get<0>(t);
      if (S.find(v) != S.end()) {
	continue;
      }
      double edge = get<1>(t);
      if (edge < priority[v]) {
	priority[v] = edge;
	q.Update(v, edge);
	parent[v] = u;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (parent[i] != -1) {
      tree_edges->push_back(
        (i < parent[i]) ? make_tuple(i, parent[i]) : make_tuple(parent[i], i));
    }
  }
}

class PrimTest : public Test {
public:
  void AddEdge(vector<list<tuple<int,double>>>* graph,
	       int u, int v, double cost) {
    (*graph)[u].push_back(make_tuple(v,cost));
    (*graph)[v].push_back(make_tuple(u,cost));
  }
};

TEST_F(PrimTest, CycleGraph) {
  vector<list<tuple<int,double>>> graph(5);
  AddEdge(&graph,0,1,1.0);
  AddEdge(&graph,1,2,2.0);
  AddEdge(&graph,2,3,3.0);
  AddEdge(&graph,3,4,4.0);
  AddEdge(&graph,4,0,5.0);

  vector<tuple<int,int>> tree_edges;
  Prim(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1),
				   make_tuple(1,2),
				   make_tuple(2,3),
				   make_tuple(3,4)));
}

TEST_F(PrimTest, TreeGraph) {
  vector<list<tuple<int,double>>> graph(6);
  AddEdge(&graph,0,1,1.0);
  AddEdge(&graph,0,2,2.0);
  AddEdge(&graph,1,3,3.0);
  AddEdge(&graph,1,4,4.0);
  AddEdge(&graph,2,5,5.0);

  vector<tuple<int,int>> tree_edges;
  Prim(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1),
				   make_tuple(0,2),
				   make_tuple(1,3),
				   make_tuple(1,4),
				   make_tuple(2,5)));
}

TEST_F(PrimTest, GeneralGraph) {
  vector<list<tuple<int,double>>> graph(6);
  AddEdge(&graph,0,1,2.0);
  AddEdge(&graph,0,2,4.0);
  AddEdge(&graph,0,4,3.1);
  AddEdge(&graph,1,2,1.0);
  AddEdge(&graph,2,4,3.2);
  AddEdge(&graph,1,3,8.0);
  AddEdge(&graph,5,1,5.0);
  AddEdge(&graph,5,2,3.3);
  AddEdge(&graph,5,4,2.0);
  AddEdge(&graph,5,3,6.0);

  vector<tuple<int,int>> tree_edges;
  Prim(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1),
				   make_tuple(0,4),
				   make_tuple(1,2),
				   make_tuple(4,5),
				   make_tuple(3,5)));
}
