#ifndef ROUTE_MANAGER_HPP
#define ROUTE_MANAGER_HPP

#include <bits/stdc++.h>
using namespace std;

#include "graph.hpp"
#include "dijkstra.hpp"

class RouteManager {
private:
    Graph graph;

public:
    // Load graph data from a file (format: u v w per line)
    bool loadMapData(const string &filename);

    // Compute shortest path between two nodes
    vector<int> computeRoute(int start, int end);

    // Display the path in a readable format
    void displayRoute(const vector<int> &path);

    // Export path to an output file
    void exportRoute(const vector<int> &path, const string &outputFile);
};

#endif