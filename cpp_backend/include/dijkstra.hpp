#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
public:
    // Returns pair: (distance vector, previous node map)
    static pair<vector<double>, unordered_map<int, int>> shortestPath(Graph &g, int start);
};

#endif