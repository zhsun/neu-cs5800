#ifndef GRAPH_KRUSKAL_H_
#define GRAPH_KRUSKAL_H_

#include <vector>
#include "graph/graph.h"

double Kruskal(const AdjacencyList& graph,
               std::vector<Edge>* tree_edges);

#endif  // GRAPH_KRUSKAL_H_
