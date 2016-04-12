#ifndef GRAPH_SCC_H_
#define GRAPH_SCC_H_

#include <vector>
#include "graph/graph.h"

void StronglyConnectedComponents(const AdjacencyList& graph,
                                 std::vector<int>& cc);

#endif  // GRAPH_SCC_H_
