#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

// 🔹 Function to load all routes from a CSV file
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "❌ Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // skip header (from,to,distance)

    while (getline(file, line)) {
        stringstream ss(line);
        string from, to, distStr;
        if (!getline(ss, from, ',')) continue;
        if (!getline(ss, to, ',')) continue;
        if (!getline(ss, distStr, ',')) continue;

        try {
            double distance = stod(distStr);
            rm.addRoute(from, to, distance);
        } catch (...) {
            cerr << "⚠ Warning: Skipped invalid line: " << line << endl;
        }
    }

    file.close();
    cout << "✅ Routes loaded successfully from " << filename << endl;
}

int main() {
    RouteManager rm;

    // Try to open the CSV file in both likely paths
    string filename = "data/city_distances.csv";

    ifstream test(filename);
    if (!test.good()) {
        filename = "../data/city_distances.csv";
        test.open(filename);
        if (!test.good()) {
            cerr << "❌ Error: Could not find city_distances.csv in data/ or ../data/" << endl;
            return 1;
        }
    }
    test.close();

    loadRoutesFromCSV(rm, filename);

    rm.displayCities();

    string src, dest;
    cout << "\nEnter source city: ";
    cin >> src;
    cout << "Enter destination city: ";
    cin >> dest;

    rm.findShortestRoute(src, dest);

    return 0;
}