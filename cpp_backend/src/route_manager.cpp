#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

RouteManager::RouteManager() : cityCount(0), graph(100) {}

void RouteManager::addCity(const string& cityName) {
    string city = Utils::toLower(cityName);
    if (cityToId.find(city) == cityToId.end()) {
        cityToId[city] = cityCount;
        idToCity[cityCount] = city;
        cityCount++;
    }
}

void RouteManager::addRoute(const string& from, const string& to, double distance) {
    addCity(from);
    addCity(to);
    int u = cityToId[Utils::toLower(from)];
    int v = cityToId[Utils::toLower(to)];
    graph.addEdge(u, v, distance);
}

void RouteManager::displayCities() const {
    cout << "Available Cities:\n";
    for (auto it = cityToId.begin(); it != cityToId.end(); ++it) {
        cout << "- " << it->first << endl;
    }
    Utils::printDivider();
}

void RouteManager::findShortestRoute(const string& source, const string& destination) {
    string src = Utils::toLower(source);
    string dest = Utils::toLower(destination);

    // Check both cities exist
    if (cityToId.find(src) == cityToId.end() || cityToId.find(dest) == cityToId.end()) {
        cout << "Error: One or both cities not found.\n";
        return;
    }

    // Run Dijkstra
    pair<vector<double>, unordered_map<int, int>> result =
        Dijkstra::shortestPath(graph, cityToId[src]);

    vector<double> dist = result.first;
    unordered_map<int, int> prev = result.second;

    int target = cityToId[dest];

    if (target >= (int)dist.size() || dist[target] == numeric_limits<double>::infinity()) {
        cout << "No route found from " << source << " to " << destination << endl;
        return;
    }

    // Reconstruct path
    stack<int> path;
    int current = target;

    while (prev.find(current) != prev.end()) {
        path.push(current);
        current = prev[current];
    }
    path.push(cityToId[src]);

    // Display path
    cout << "Shortest path from " << source << " to " << destination << ":\n";
    while (!path.empty()) {
        int id = path.top();
        path.pop();
        cout << idToCity[id];
        if (!path.empty()) cout << " -> ";
    }

    cout << "\nTotal distance: " << dist[target] << " km\n";
    Utils::printDivider();
}
