#include "Dijkstra.h"
#include "graph.h"

int main() {
  Graph *graph = new Graph(8, 13);
  graph->insert_edge(0, 1, 3);
  graph->insert_edge(1, 2, 1);
  graph->insert_edge(1, 3, 4);
  graph->insert_edge(1, 4, 1);
  graph->insert_edge(2, 4, 1);
  graph->insert_edge(2, 5, 10);
  graph->insert_edge(3, 4, 1);
  graph->insert_edge(3, 6, 1);
  graph->insert_edge(4, 5, 7);
  graph->insert_edge(4, 6, 8);
  graph->insert_edge(4, 7, 4);
  graph->insert_edge(5, 7, 6);
  graph->insert_edge(6, 7, 1);
  int min = HeapDijkstra(&graph, 0);
  std::cout << " Min way from start position - " << min << std::endl;
  return 0;
}
