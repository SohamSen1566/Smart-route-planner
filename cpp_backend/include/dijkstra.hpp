#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include "graph.hpp"

class Dijkstra {
public:
    static std::vector<int> shortestPath(Graph &g, int start, int end);
};

#endif
