#include <algorithm>
#include <list>
#include <vector>
#include "gmock/gmock.h"

using namespace std;
using namespace testing;

class DFSVisitor {
public:
  virtual ~DFSVisitor() { };

  virtual void Preprocess(int node) { }
  virtual void ProcessNeighbor(int node, int neighbor) { }
  virtual void Postprocess(int node) { }
};

class FinishTimeOrderVisitor : public DFSVisitor {
public:
  virtual ~FinishTimeOrderVisitor() { }

  virtual void Postprocess(int node) {
    sorted_.push_back(node);
  }

  void GetSorted(vector<int>* s) {
    s->resize(sorted_.size());
    copy(sorted_.begin(), sorted_.end(), s->begin());
  }

private:
  vector<int> sorted_;
};

class LabelComponentVisitor : public DFSVisitor {
public:
  virtual ~LabelComponentVisitor() { }

  LabelComponentVisitor(int vertex_num) : cc_(vertex_num, -1), counter_(0) { }

  virtual void Preprocess(int node) {
    if (cc_[node] == -1) {
      // Found a new connected component. Init its label.
      cc_[node] = counter_++;
    }
  }

  virtual void ProcessNeighbor(int node, int neighbor) {
    cc_[neighbor] = cc_[node];
  }

  void GetCC(vector<int>* s) {
    s->resize(cc_.size());
    copy(cc_.begin(), cc_.end(), s->begin());
  }

private:
  vector<int> cc_;
  int counter_;
};

void Explore(const vector<list<int>>& graph,
	     int node,
	     vector<bool>* visited,
	     DFSVisitor* visitor) {
  (*visited)[node] = true;
  visitor->Preprocess(node);
  for (int neighbor : graph[node]) {
    if (!(*visited)[neighbor]) {
      visitor->ProcessNeighbor(node, neighbor);
      Explore(graph, neighbor, visited, visitor);
    }
  }
  visitor->Postprocess(node);
}

void DFS(const vector<list<int>>& graph,
	 const vector<int>& visit_order,
	 DFSVisitor* visitor) {
  vector<bool> visited(graph.size(), false);
  for (int node : visit_order) {
    if (!visited[node]) {
      Explore(graph, node, &visited, visitor);
    }
  }
}

// SCC (strongly-connected-components) takes a graph in adjacency list
// format, and returns a vector that tells the compoent number of each
// vertex.
void SCC(const vector<list<int>>& graph, vector<int>* cc) {
  int n = graph.size();
  vector<int> visit_order(n);
  for (int i = 0; i < n; ++i) {
    visit_order[i] = i;
  }
  FinishTimeOrderVisitor order_visitor;
  DFS(graph, visit_order, &order_visitor);

  vector<int> finish_time_order;
  order_visitor.GetSorted(&finish_time_order);

  LabelComponentVisitor cc_visitor(n);
  DFS(graph, finish_time_order, &cc_visitor);
  cc_visitor.GetCC(cc);
}


TEST(SCCTest, NoEdgeGraph) {
  vector<list<int>> graph(5);
  vector<int> cc(5);
  SCC(graph, &cc);
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[4]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[3], Ne(cc[4]));
}

TEST(SCCTest, TreeGraph) {
  vector<list<int>> graph = {{1,2},{3,4},{5},{},{},{}};
  vector<int> cc(6);
  SCC(graph, &cc);
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[4]));
  EXPECT_THAT(cc[0], Ne(cc[5]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[3], Ne(cc[4]));
}

TEST(SCCTest, GeneralGraph) {
  vector<list<int>> graph(10);
  graph[1] = {0,4};
  graph[2] = {1,5};
  graph[3] = {1};
  graph[4] = {1};
  graph[5] = {2};
  graph[6] = {4,7};
  graph[7] = {5,9};
  graph[8] = {6};
  graph[9] = {8};
  vector<int> cc(10);
  SCC(graph, &cc);
  // 0 itself forms a cc.
  // 3 itself forms a cc.
  // 1 and 4 form a cc.
  EXPECT_THAT(cc[1], Eq(cc[4]));
  // 2 and 5 form a cc.
  EXPECT_THAT(cc[2], Eq(cc[5]));
  // 6, 7, 8, and 9 form a cc.
  EXPECT_THAT(cc[6], Eq(cc[7]));
  EXPECT_THAT(cc[6], Eq(cc[8]));
  EXPECT_THAT(cc[6], Eq(cc[9]));
  // Check different cc are numbered differently.
  EXPECT_THAT(cc[0], Ne(cc[1]));
  EXPECT_THAT(cc[0], Ne(cc[2]));
  EXPECT_THAT(cc[0], Ne(cc[3]));
  EXPECT_THAT(cc[0], Ne(cc[6]));
  EXPECT_THAT(cc[1], Ne(cc[2]));
  EXPECT_THAT(cc[1], Ne(cc[3]));
  EXPECT_THAT(cc[1], Ne(cc[6]));
  EXPECT_THAT(cc[2], Ne(cc[3]));
  EXPECT_THAT(cc[2], Ne(cc[6]));
  EXPECT_THAT(cc[3], Ne(cc[6]));
}
