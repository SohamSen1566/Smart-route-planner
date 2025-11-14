# Smart-route-planner

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
1. Compile
g++ main.cpp graph.cpp dijkstra.cpp route_manager.cpp utils.cpp -o routefinder

2. Run
./routefinder "Pune" "Mumbai"

Example Output
Shortest path from Pune to Mumbai:
pune -> mumbai
Total distance: 150 km