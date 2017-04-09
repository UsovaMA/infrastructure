#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include <vector>
#include <iostream>
#include <set>
#include <stack>

const int INF = 1000000000;

// list of adjacent edges for each vertex
struct edge {
  int vFrom, vTo;
  int weight;
};

edge make_edge(int vFrom_, int vTo_, int weight_);
int Dijkstra(std::vector< std::vector <edge> > g, int start, int end);

#endif  // INCLUDE_DIJKSTRA_H_
