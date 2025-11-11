//adtiya
#include <bits/stdc++.h>
using namespace std;
#include "route_manager.hpp"

bool RouteManager::loadMapData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    int u, v;
    double w;
    while (file >> u >> v >> w) {
        graph.addEdge(u, v, w);
    }

    file.close();
    cout << "Map data loaded successfully from " << filename << "\n";
    return true;
}

vector<int> RouteManager::computeRoute(int start, int end) {
    cout << "Calculating shortest path from " << start << " → " << end << "...\n";
    auto path = Dijkstra::shortestPath(graph, start, end);
    return path;
}

void RouteManager::displayRoute(const vector<int> &path) {
    if (path.empty()) {
        cout << " No path found.\n";
        return;
    }

    cout << " Shortest Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << "\n";
}

void RouteManager::exportRoute(const vector<int> &path, const string &outputFile) {
    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "Error: Could not open output file " << outputFile << "\n";
        return;
    }

    out << "Shortest Path:\n";
    for (size_t i = 0; i < path.size(); ++i) {
        out << path[i];
        if (i != path.size() - 1)
            out << " -> ";
    }
    out << "\n";
    out.close();

    cout << "Path exported to " << outputFile << "\n";
}
