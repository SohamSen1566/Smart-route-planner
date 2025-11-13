#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

// Load CSV
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header

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
            // Ignore invalid lines
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    RouteManager rm;

    // Use correct CSV path
    string filename = "cpp_backend/data/city_distances.csv";
    loadRoutesFromCSV(rm, filename);

    // Expect arguments from Flask
    if (argc < 3) {
        cout << "Error: Please provide source and destination." << endl;
        return 1;
    }

    string src = argv[1];
    string dest = argv[2];

    // Compute shortest route
    rm.findShortestRoute(src, dest);

    return 0;
}
