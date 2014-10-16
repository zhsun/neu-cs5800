#include <list>
#include <tuple>
#include <vector>
#include "gmock/gmock.h"
#include "data-structure/disjoint-set/disjoint_set.cpp"

using namespace std;
using namespace testing;

// Forward declare.
void ExtractEdgesFromUndirectedGraph(const vector<list<tuple<int,double>>>& graph,
				     vector<tuple<int,int,double>>* edges);
bool EdgeComparator(const tuple<int,int,double>&, const tuple<int,int,double>&);

// Kruskal takes an undirected graph in adjacency list format (each
// tuple has vertex id [int] and edge weight [double]), and produces
// the MST. Selected edges are copied to *edges* parameter.
void Kruskal(const vector<list<tuple<int,double>>>& graph,
	     vector<tuple<int,int,double>>* tree_edges) {
  // 1. Extract all edges from graph with their costs.
  vector<tuple<int,int,double>> edges;
  ExtractEdgesFromUndirectedGraph(graph, &edges);
  // 2. Sort edges by their cost.
  sort(edges.begin(), edges.end(), EdgeComparator);
  // 3. Go over all edges and use disjoint set to select tree edges.
  DisjointSet ds(graph.size());
  for (const tuple<int,int,double>& e : edges) {
    if (ds.Find(get<0>(e)) != ds.Find(get<1>(e))) {
      tree_edges->push_back(e);
      ds.Union(get<0>(e),get<1>(e));
    }
  }
}

void ExtractEdgesFromUndirectedGraph(const vector<list<tuple<int,double>>>& graph,
				     vector<tuple<int,int,double>>* edges) {
  for (int u = 0; u < graph.size(); ++u) {
    const list<tuple<int,double>>& u_edges = graph[u];
    for (const tuple<int,double>& e : u_edges) {
      int v;
      double cost;
      tie(v,cost) = e;
      if (u < v) {
	edges->push_back(make_tuple(u,v,cost));
      }
    }
  }
}

bool EdgeComparator(const tuple<int,int,double>& a,
		    const tuple<int,int,double>& b) {
  double cost_a = get<2>(a);
  double cost_b = get<2>(b);
  return cost_a < cost_b;
}

class KruskalTest : public Test {
public:
  void AddEdge(vector<list<tuple<int,double>>>* graph,
	       int u, int v, double cost) {
    (*graph)[u].push_back(make_tuple(v,cost));
    (*graph)[v].push_back(make_tuple(u,cost));
  }
};

TEST_F(KruskalTest, CycleGraph) {
  vector<list<tuple<int,double>>> graph(5);
  AddEdge(&graph,0,1,1.0);
  AddEdge(&graph,1,2,2.0);
  AddEdge(&graph,2,3,3.0);
  AddEdge(&graph,3,4,4.0);
  AddEdge(&graph,4,0,5.0);

  vector<tuple<int,int,double>> tree_edges;
  Kruskal(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1,1.0),
				   make_tuple(1,2,2.0),
				   make_tuple(2,3,3.0),
				   make_tuple(3,4,4.0)));
}

TEST_F(KruskalTest, TreeGraph) {
  vector<list<tuple<int,double>>> graph(6);
  AddEdge(&graph,0,1,1.0);
  AddEdge(&graph,0,2,2.0);
  AddEdge(&graph,1,3,3.0);
  AddEdge(&graph,1,4,4.0);
  AddEdge(&graph,2,5,5.0);

  vector<tuple<int,int,double>> tree_edges;
  Kruskal(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1,1.0),
				   make_tuple(0,2,2.0),
				   make_tuple(1,3,3.0),
				   make_tuple(1,4,4.0),
				   make_tuple(2,5,5.0)));
}

TEST_F(KruskalTest, GeneralGraph) {
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

  vector<tuple<int,int,double>> tree_edges;
  Kruskal(graph, &tree_edges);
  EXPECT_THAT(tree_edges,
	      UnorderedElementsAre(make_tuple(0,1,2.0),
				   make_tuple(0,4,3.1),
				   make_tuple(1,2,1.0),
				   make_tuple(4,5,2.0),
				   make_tuple(3,5,6.0)));
}
