#include <vector>
#include <utility>
#include <set>
#include "Dijkstra.h"

edge make_edge(int vFrom_, int vTo_, int weight_) {
  edge c;
  c.vFrom = vFrom_;
  c.vTo = vTo_;
  c.weight = weight_;
  return c;
}

int Dijkstra(std::vector< std::vector<edge> > g, int start, int end) {
  int* parent = new int[g.size()];
  std::vector<int> dist(g.size());
  std::set<std::pair<int, int>> s;
  int flag;

  if ((g.size() == 0) || ((end == start) && (g[0][0].vFrom != end)))
    throw std::logic_error("Input Error\n");

  if (end == start)
    return 0;

  for (int i = 0; i < g.size(); i++)
    parent[i] = -1;
  for (int i = 0; i < g.size(); i++)
    dist[i] = INF;
  dist[start] = 0;
  s.insert(std::make_pair(dist[start], start));

  while (!s.empty()) {
    int v = s.begin()->second;
    if (v == end) {
      int i = 1;
      std::cout << "Our path: ";
      while ( i <= flag ) {
        std::cout << parent[i];
        std::cout << " ";
        i++;
      }
      std::cout << "" << std::endl;
      std::cout << "Shortest path length: ";
      std::cout << s.begin()->first;
      std::cout << "" << std::endl;
      return s.begin()->first;
    }
    s.erase(s.begin());
    for (int j = 0; j < g[v].size(); j++) {
      int u = g[v][j].vTo;
      if (u < 0) break;
      int w = g[v][j].weight;
      if (dist[u] > dist[v] + w) {
        s.erase(std::make_pair(dist[u], u));
        dist[u] = dist[v] + w;
        parent[u] = v;
        s.insert(std::make_pair(dist[u], u));
      }
      flag = u;
    }
  }
  return 0;
}
