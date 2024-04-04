
# Public Transportation Management System

## Introduction

This C++ program is a Public Transportation Management System that allows users to manage stations, routes, and fares for a transportation network. It provides functionality for adding stations, defining routes between stations, calculating fares, and performing various operations on the transportation network.

## Features

- **User Input or Static Input**: Users can choose to input data manually or use pre-defined data for the transportation network.

- **Graph Operations**: The program supports basic graph operations such as Breadth-First Search (BFS), Depth-First Search (DFS), and printing the adjacency list.

- **Modification of Graph**: Users can modify the transportation network by adding or removing stations, updating routes, or adjusting fares.

- **Fare Calculation**: The program can calculate fares based on the shortest path between two stations using Dijkstra's algorithm.

- **Important Stations Identification**: It identifies important stations in the transportation network using the Articulation Point algorithm.

## Usage

1. **Compile**: Compile the program using a C++ compiler.
   ```bash
   g++ main.cpp -o transportation_system
   ```

2. **Run**: Execute the compiled program.
   ```bash
   ./transportation_system
   ```

3. **Choose Input Mode**: Select either user input or static input for defining the transportation network.

4. **Perform Operations**: Choose from various operations such as BFS, DFS, modifying the graph, calculating fares, or identifying important stations.

5. **Exit**: Exit the program when done.

## Requirements

- C++ compiler (e.g., g++)
- Standard Template Library (STL)
