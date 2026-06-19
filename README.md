# Route Optimization using Graph Theory

## Overview

This project models a smart transportation network using Graph Theory concepts. A synthetic network of 500 cities is represented as a weighted undirected graph, where cities are vertices and roads are weighted edges representing distances.

The objective is to analyze network connectivity, detect clusters of connected cities, and determine optimal routes using classical graph algorithms.

---

## Problem Statement

Modern transportation and logistics systems require efficient route planning and network analysis. This project investigates how graph-theoretic algorithms can be applied to:

- Analyze network connectivity
- Detect connected city clusters
- Identify shortest transportation routes
- Support route optimization and logistics planning

---

## Network Design

- 500 cities represented as graph vertices
- Randomly generated transportation network
- Each city connected to 2–6 neighboring cities
- Road distances randomly assigned between 5 km and 50 km
- Adjacency List representation used for efficient storage

---

## Algorithms Implemented

### Depth First Search (DFS)

Used for:

- Connectivity Analysis
- Graph Traversal
- Cluster Discovery

### Connected Component Detection

Used to identify:

- Total connected regions
- Largest cluster
- Smallest cluster
- Component-wise city grouping

### Dijkstra's Algorithm

Used to:

- Compute shortest paths
- Determine minimum travel distances
- Identify reachable and unreachable cities

---

## Complexity Analysis

| Algorithm | Time Complexity | Space Complexity |
|------------|----------------|------------------|
| DFS | O(V + E) | O(V) |
| Connected Components | O(V + E) | O(V) |
| Dijkstra | O(E log V) | O(V) |
| Adjacency List | O(V + E) | O(V + E) |

---

## Applications

### Transportation Systems
- Route Optimization
- Traffic Management

### Logistics & Supply Chain
- Delivery Route Planning
- Fuel Cost Reduction

### Emergency Services
- Ambulance Routing
- Disaster Response Planning

### Digital Mapping
- Navigation Systems
- Location-Based Services

---

## Tools & Technologies

- C++
- Graph Theory
- DFS
- Dijkstra's Algorithm
- Adjacency Lists
- STL (Priority Queue, Vector)

---

## Repository Contents

```text
route-optimization-graph-theory/

├── README.md
├── Assignment_Report.pdf
└── ass2.cpp
```

---

## Key Learning Outcomes

- Applied graph-theoretic concepts to transportation networks.
- Implemented efficient shortest-path and connectivity algorithms.
- Analyzed algorithmic complexity for large-scale networks.
- Explored real-world applications in logistics and route optimization.# route-optimization-graph-theory
