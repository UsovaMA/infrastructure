#include <set>
#include "Dijkstra.h"

int* Dijkstra(int start) {
  int* parent = new int[N];
  int* dist = new int[N];
  std::set<std::pair<int, int>> s;

  for (int i = 0; i < N; i++) 
    parent[i] = -1;
  for (int i = 0; i < N; i++) 
    dist[i] = INF;
  dist[start] = 0;
  s.insert(std::make_pair(dist[start], start));

  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
	for (int j = 0; j < g[v].size(); j++) {
      int u = g[v][j].vTo;
      int w = g[v][j].weight;
      if (dist[u] > dist[v] + w) {
        s.erase(std::make_pair(dist[u], u));
        dist[u] = dist[v] + w;
        parent[u] = v;
        s.insert(std::make_pair(dist[u], u));
      }
	}
  }
  return parent;
}
