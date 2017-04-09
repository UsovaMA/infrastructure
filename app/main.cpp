#include "Dijkstra.h"
#include <vector>

int main() {
  int start = 0, end = 5;
  std::vector< std::vector<edge> > g =
  { { make_edge(0, 1, 1) },
  { make_edge(1, 2, 2), make_edge(1, 4, 8) },
  { make_edge(2, 3, 3) },
  { make_edge(3, 4, 5) },
  { make_edge(4, 5, 1) },
  { make_edge(5, -1, -1) } };
  Dijkstra(g, start, end);
}

