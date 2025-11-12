#include "route_manager.hpp"
#include "utils.hpp"
#include <bits/stdc++.h>
using namespace std;

int main() {
    RouteManager rm;

    rm.addRoute("Pune", "Mumbai", 150);
    rm.addRoute("Mumbai", "Nashik", 180);
    rm.addRoute("Nashik", "Nagpur", 700);
    rm.addRoute("Pune", "Bangalore", 850);
    rm.addRoute("Bangalore", "Hyderabad", 570);

    rm.displayCities();

    string src, dest;
    cout << "Enter source city: ";
    cin >> src;
    cout << "Enter destination city: ";
    cin >> dest;

    rm.findShortestRoute(src, dest);

return 0;
}
