# Smart-route-planner

Group Members :-

Aditya Mahesh Chhajed - B24CM1073
Vedansh Manish Buchasia - B24CM1066
Soham Sen - B24EE1076
Arpit - B24CS1015

City Route Finder – C++ Shortest Path Project :-

A simple and efficient C++ project that finds the shortest route between two cities using Dijkstra’s Algorithm.
City distances are loaded from a CSV file, and the program outputs both the full path and total distance.


Features:- 

1. Load routes dynamically from a CSV file

2. Graph implemented using adjacency lists

3. Dijkstra’s algorithm for shortest path

4. Automatic city-to-ID mapping

5. Clean command-line interface

6. Human-readable output


Project Structure:-

/cpp_backend
│── data/
│   └── city_distances.csv
│
│── graph.hpp
│── graph.cpp
│── dijkstra.hpp
│── dijkstra.cpp
│── route_manager.hpp
│── route_manager.cpp
│── utils.hpp
│── utils.cpp
│── main.cpp


How to Compile & Run
1. Open cpp_backend folder
cd cpp_backend

2. Compile
g++ src/*.cpp -I include -o dijkstra.exe

3. Revisit your Smart-route-planner folder
cd "path"

4. python app.py

5. visit local host 

Example Output
Shortest path from Agra to Pune:
agra -> gwalior -> bhopal -> indore -> nasik -> pune
Total distance: 1357.96 km