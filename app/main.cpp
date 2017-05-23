#include "Dijkstra.h"
#include "graph.h"

int main() {
  Graph *graph = new Graph(8, 12);

  graph->insert_edge(0, 1, 3);
  graph->insert_edge(1, 2, 1);
  graph->insert_edge(1, 3, 4);
  graph->insert_edge(1, 4, 4);
  graph->insert_edge(2, 5, 10);
  graph->insert_edge(3, 4, 1);
  graph->insert_edge(3, 6, 1);
  graph->insert_edge(4, 5, 1);
  graph->insert_edge(4, 6, 8);
  graph->insert_edge(4, 7, 4);
  graph->insert_edge(5, 7, 6);
  graph->insert_edge(6, 7, 1);

  int min_1 = HeapDijkstra(&graph, 0);
  std::cout << " Min way from start position to end - " << min_1 << std::endl;

  std::vector < std::vector < std::pair<int, int> > > g(8);
  g[0] = std::vector< std::pair<int, int>>(1);
  g[0][0].first = 1;
  g[0][0].second = 3;
  g[1] = std::vector< std::pair<int, int>>(3);
  g[1][0].first = 2;
  g[1][0].second = 1;
  g[1][1].first = 3;
  g[1][1].second = 4;
  g[1][2].first = 4;
  g[1][2].second = 4;
  g[2] = std::vector< std::pair<int, int>>(1);
  g[2][0].first = 5;
  g[2][0].second = 10;
  g[3] = std::vector< std::pair<int, int>>(2);
  g[3][0].first = 4;
  g[3][0].second = 1;
  g[3][1].first = 6;
  g[3][1].second = 1;
  g[4] = std::vector< std::pair<int, int>>(3);
  g[4][0].first = 5;
  g[4][0].second = 1;
  g[4][1].first = 6;
  g[4][1].second = 8;
  g[4][2].first = 7;
  g[4][2].second = 4;
  g[5] = std::vector< std::pair<int, int>>(1);
  g[5][0].first = 7;
  g[5][0].second = 6;
  g[6] = std::vector< std::pair<int, int>>(1);
  g[6][0].first = 7;
  g[6][0].second = 1;

  int min_2 = TreeDijkstra(g, 0);
  std::cout << " Min way from start position to end - " << min_2 << std::endl;
  return 0;
}
