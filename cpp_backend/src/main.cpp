#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

<<<<<<<<< Temporary merge branch 1
=========

>>>>>>>>> Temporary merge branch 2
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }

    string line;
<<<<<<<<< Temporary merge branch 1
    getline(file, line); // skip header (from,to,distance)
=========
    getline(file, line);
>>>>>>>>> Temporary merge branch 2

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
<<<<<<<<< Temporary merge branch 1
            cerr << "Warning: Skipped invalid line: " << line << endl;
=========
            cout << "Warning: Skipped invalid line: " << line << endl;
>>>>>>>>> Temporary merge branch 2
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
<<<<<<<<< Temporary merge branch 1
            cerr << "Error: Could not find city_distances.csv in data/ or ../data/" << endl;
=========
            cout << "Error: Could not find city_distances.csv in data/ or ../data/" << endl;
>>>>>>>>> Temporary merge branch 2
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