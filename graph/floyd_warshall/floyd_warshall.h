#ifndef GRAPH_FLOYD_WARSHALL_H_
#define GRAPH_FLOYD_WARSHALL_H_

#include <limits>
#include <vector>
#include "graph/graph.h"

const double Inf = std::numeric_limits<double>::max();

void FloydWarshall(const std::vector<std::vector<double>>& graph,
                   std::vector<std::vector<double>>& dist);

#endif  // GRAPH_FLOYD_WARSHALL_H_
