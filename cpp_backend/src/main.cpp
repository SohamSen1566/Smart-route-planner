#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
// 🔹 Function to load all routes from a CSV file
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
<<<<<<< HEAD
        cerr << "Error: Could not open file " << filename << endl;
=======
        cerr << "❌ Error: Could not open file " << filename << endl;
>>>>>>> 24c85d5 (updated the main file and integrated the csv data file into the project structure.)
=======
// Function to load all routes from a CSV file
void loadRoutesFromCSV(RouteManager &rm, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
>>>>>>> 8b4ad22 (Updated main)
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
<<<<<<< HEAD
<<<<<<< HEAD
            cerr << "Warning: Skipped invalid line: " << line << endl;
=======
            cerr << "⚠ Warning: Skipped invalid line: " << line << endl;
>>>>>>> 24c85d5 (updated the main file and integrated the csv data file into the project structure.)
=======
            cout << "Skipped invalid line: " << line << endl;
>>>>>>> 8b4ad22 (Updated main)
        }
    }

    file.close();
<<<<<<< HEAD
    cout << "Routes loaded successfully from " << filename << endl;
=======
    cout << "✅ Routes loaded successfully from " << filename << endl;
>>>>>>> 24c85d5 (updated the main file and integrated the csv data file into the project structure.)
}

int main() {
    RouteManager rm;

<<<<<<< HEAD
=======
    // Try to open the CSV file in both likely paths
>>>>>>> 24c85d5 (updated the main file and integrated the csv data file into the project structure.)
    string filename = "data/city_distances.csv";

    ifstream test(filename);
    if (!test.good()) {
        filename = "../data/city_distances.csv";
        test.open(filename);
        if (!test.good()) {
<<<<<<< HEAD
<<<<<<< HEAD
            cerr << "Error: Could not find city_distances.csv in data/ or ../data/" << endl;
=======
            cerr << "❌ Error: Could not find city_distances.csv in data/ or ../data/" << endl;
>>>>>>> 24c85d5 (updated the main file and integrated the csv data file into the project structure.)
=======
            cout << "Could not find city_distances.csv " << endl;
>>>>>>> 8b4ad22 (Updated main)
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
