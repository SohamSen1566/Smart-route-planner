#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
=======

>>>>>>> 491cdbf779a4564d080facc755f77effac74de64
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
<<<<<<< HEAD
    getline(file, line); // skip header (from,to,distance)
=======
    getline(file, line);
>>>>>>> 491cdbf779a4564d080facc755f77effac74de64

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
<<<<<<< HEAD
            cerr << "Warning: Skipped invalid line: " << line << endl;
=======
            cout << "Warning: Skipped invalid line: " << line << endl;
>>>>>>> 491cdbf779a4564d080facc755f77effac74de64
        }
    }

    file.close();
    cout << "Routes loaded successfully from " << filename << endl;
}

int main() {
    RouteManager rm;

    string filename = "data/city_distances.csv";

    ifstream test(filename);
    if (!test.good()) {
        filename = "../data/city_distances.csv";
        test.open(filename);
        if (!test.good()) {
<<<<<<< HEAD
            cerr << "Error: Could not find city_distances.csv in data/ or ../data/" << endl;
=======
            cout << "Error: Could not find city_distances.csv in data/ or ../data/" << endl;
>>>>>>> 491cdbf779a4564d080facc755f77effac74de64
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