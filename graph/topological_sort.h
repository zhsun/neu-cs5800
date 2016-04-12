#ifndef GRAPH_TOPOLOGICAL_SORT_H_
#define GRAPH_TOPOLOGICAL_SORT_H_

#include "graph/graph.h"

// TopologicalSort takes a DAG in adjacency list format, and output
// the topological order.
void TopologicalSort(const AdjacencyList& graph,
                     std::vector<Vertex>& sorted);

#endif  // GRAPH_TOPOLOGICAL_SORT_H_
