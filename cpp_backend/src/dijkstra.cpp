#include "dijkstra.hpp"
using namespace std;

pair<vector<double>, unordered_map<int, int>> Dijkstra::shortestPath(Graph &g, int start) {
    int n = g.size();

    // Initialize distances
    vector<double> dist(n, numeric_limits<double>::infinity());
    unordered_map<int, int> prev;
    dist[start] = 0.0;

    // Min-heap priority queue: (distance, node)
    typedef pair<double, int> PDI;
    priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
    pq.push(make_pair(0.0, start));

    while (!pq.empty()) {
        PDI current = pq.top();
        pq.pop();

        double d = current.first;
        int u = current.second;

        if (d > dist[u])
            continue;

        // Explore neighbors
        const vector<pair<int, double>>& neighbors = g.getNeighbors(u);
        for (size_t i = 0; i < neighbors.size(); ++i) {
            int v = neighbors[i].first;
            double w = neighbors[i].second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return make_pair(dist, prev);
}