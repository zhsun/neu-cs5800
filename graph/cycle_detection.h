#ifndef GRAPH_CYCLE_DETECTION_H_
#define GRAPH_CYCLE_DETECTION_H_

#include "graph/graph.h"

// HasCycle makes use of DFS to detect cycles in graph.
bool HasCycle(const AdjacencyList& graph);

#endif  // GRAPH_CYCLE_DETECTION_H_
