#ifndef INCLUDE_ADD_H_
#define INCLUDE_ADD_H_
#include <vector>

const int N = 100000;
const int INF = 1 << 30;

// список смежных рёбер для каждой вершины
struct mytype {
  int vFrom, vTo;
  int weight;
};
std::vector<mytype> g[N];

int* Dijkstra(int start);

#endif  // INCLUDE_ADD_H_
