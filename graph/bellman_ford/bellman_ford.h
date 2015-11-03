#ifndef GRAPH_BELLMAN_FORD_H_
#define GRAPH_BELLMAN_FORD_H_

#include <vector>
#include "graph/graph.h"

// Function will return true if there is a negatively weighted cycle,
// and false otherwise.
bool BellmanFord(const AdjacencyList& graph,
                 Vertex s,
                 std::vector<double>* distance,
                 std::vector<Vertex>* parent);

#endif  // GRAPH_BELLMAN_FORD_H_
