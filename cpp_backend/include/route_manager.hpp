#ifndef ROUTE_MANAGER_HPP
#define ROUTE_MANAGER_HPP

#include <bits/stdc++.h>
#include "graph.hpp"
#include "dijkstra.hpp"

using namespace std;

class RouteManager {
private:
    Graph graph;
    unordered_map<string, int> cityToId;
    unordered_map<int, string> idToCity;
    int cityCount;

public:
    RouteManager();

    void addCity(const string& cityName);
    void addRoute(const string& from, const string& to, double distance);
    void displayCities() const;
    void findShortestRoute(const string& source, const string& destination);
};

#endif
