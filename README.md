
# Public Transportation Management System (Metro)

## Introduction

`metro.cpp` is a C++ program representing a Public Transportation Management System designed specifically for managing metro stations, routes, and fares. It provides users with the ability to manipulate the transportation network, calculate fares, and identify important stations.

## Features

- **User Input or Static Input**: The program offers the flexibility for users to input data manually or utilize pre-defined data for the transportation network.

- **Graph Operations**: Basic graph operations such as Breadth-First Search (BFS), Depth-First Search (DFS), and printing the adjacency list are supported.

- **Graph Modification**: Users have the capability to modify the transportation network by adding or removing stations, updating routes, or adjusting fares.

- **Fare Calculation**: Using Dijkstra's algorithm, the program can calculate fares based on the shortest path between two stations.

- **Important Stations Identification**: The program identifies important stations within the transportation network using the Articulation Point algorithm.

## Usage

1. **Compile**: Compile the `metro.cpp` program using a C++ compiler.
   ```bash
   g++ metro.cpp -o metro
   ```

2. **Run**: Execute the compiled program.
   ```bash
   ./metro
   ```

3. **Input Mode Selection**: Choose either user input or static input mode for defining the transportation network.

4. **Operations**: Select from various operations such as BFS, DFS, modifying the graph, calculating fares, or identifying important stations.

5. **Exit**: Terminate the program when finished.

## Requirements

- C++ compiler (e.g., g++)
- Standard Template Library (STL)

