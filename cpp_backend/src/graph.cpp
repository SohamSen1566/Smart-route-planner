// arpit 
#include "graph.hpp"

Graph::Graph(int n) : numVertices(n) {
    adjList.resize(n);
}

void Graph::addEdge(int u, int v, double weight) {
    if (u >= numVertices || v >= numVertices) return;
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // undirected
}

const vector<pair<int, double>>& Graph::getNeighbors(int u) const {
    return adjList[u];
}

int Graph::size() const {
    return numVertices;
}