#ifndef GRAPH_DIJKSTRA_H_
#define GRAPH_DIJKSTRA_H_

#include <vector>
#include "graph/graph.h"

void Dijkstra(const AdjacencyList& graph,
              Vertex s,
              std::vector<double>* distance,
              std::vector<Vertex>* parent);

#endif  // GRAPH_DIJKSTRA_H_
