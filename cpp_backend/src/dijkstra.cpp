#include "dijkstra.hpp"
#include<bits/stdc++.h>

std::vector<int> Dijkstra::shortestPath(Graph &g, int start, int end) {
    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> parent;
    auto cmp = [&](int left, int right) { return dist[left] > dist[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);

    for (auto node : g.getAllNodes()) dist[node] = 1e9;
    dist[start] = 0;
    pq.push(start);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        for (auto edge : g.getNeighbors(u)) {
            int v = edge.dest;
            double weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(v);
            }
        }
    }

    std::vector<int> path;
    for (int at = end; at != start; at = parent[at]) path.push_back(at);
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}
