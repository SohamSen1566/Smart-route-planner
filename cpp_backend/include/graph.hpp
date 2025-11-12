// arpit

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, double>>> adjList;

public:
    Graph(int n = 0);
    void addEdge(int u, int v, double weight);
    const vector<pair<int, double>>& getNeighbors(int u) const;
    int size() const;
};

#endif