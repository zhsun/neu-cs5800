#ifndef GRAPH_PRIM_H_
#define GRAPH_PRIM_H_

#include <vector>
#include "graph/graph.h"

double Prim(const AdjacencyList& graph, std::vector<Edge>* tree_edges);

#endif  // GRAPH_PRIM_H_
