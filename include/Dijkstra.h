#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include "graph.h"
#include "d_heap.h"
#include "priority_queue.h"
#include "RBtree.h"

const int INF = 10000000;

class Dijkstra_Data: public Data {
 public:
  int num;
  Dijkstra_Data(int num, int p) {
    this->num = num;
    priority = p;
  }
};

int HeapDijkstra(Graph ** _graph, int start);
int TreeDijkstra(std::vector < std::vector < std::pair<int, int> > > g, int start);

#endif  // INCLUDE_DIJKSTRA_H_
