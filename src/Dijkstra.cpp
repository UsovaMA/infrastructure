#include "Dijkstra.h"
#include <vector>
#include <utility>

/*    Алгортм Дейкстры    */
/*        на д-куче       */

int HeapDijkstra(Graph **_graph, int start) {
  std::cout << "DIJKSTRA ALGORITHM ON HEAP" << std::endl;
  // проверка корректности входных данных
  int verices = (*_graph)->get_ver();
  if (!verices)
    throw std::logic_error("Error: there in not verix in graph.\n");
  if (start < 0 || start > verices)
    throw std::logic_error("Input error: wrong start verix.\n");

  // подготовка данных для работы алгоритма
  int edge_ = (*_graph)->get_size();
  Data** dist = new Data*[verices];
  int* p = new int[verices];

  for (int i = 0; i < verices; i++) {
    p[i] = 0;
    dist[i] = new Dijkstra_Data(i, INF);
  }
  dist[start]->priority = 0;
  PriorityQueueHeap* q = new PriorityQueueHeap(dist, verices, 2);
  Edges** edges = (*_graph)->get_edge_mas();

  // алгоритм Дейкстры
  while (!q->isEmpty()) {
    int current = (reinterpret_cast<Dijkstra_Data*>(q->pop(0)))->num;
    int d;
    for (int i = 0; i < edge_; i++) {
      if (current == edges[i]->x) {
        d = dist[edges[i]->y]->priority;
        if (d > dist[edges[i]->x]->priority + (*_graph)->get_weight(edges[i]->x, edges[i]->y)) {
          dist[edges[i]->y]->priority = dist[edges[i]->x]->priority +
            (*_graph)->get_weight(edges[i]->x, edges[i]->y);
          p[edges[i]->y] = edges[i]->x;
          q->update();
        }
      }
      if (current == edges[i]->y) {
        d = dist[edges[i]->x]->priority;
        if (d > dist[edges[i]->y]->priority + (*_graph)->get_weight(edges[i]->x, edges[i]->y)) {
          dist[edges[i]->x]->priority = dist[edges[i]->y]->priority +
            (*_graph)->get_weight(edges[i]->x, edges[i]->y);
          p[edges[i]->x] = edges[i]->y;
          q->update();
        }
      }
    }
  }

  // вывод и удаление (можно было реализовать воврат полученного dist)
  int min;
  std::cout << std::endl;
  std::cout << "Process of search shortest way: " << std::endl;
  for (int i = 1; i < verices; i++) {
      std::cout << " -> " << p[i];
  }
  std::cout << " -> " << verices - 1;
  std::cout << std::endl;
  for (int i = 0; i < verices; i++) {
    if (i == start) {
      std::cout << "Start position: " << start << std::endl;
      continue;
    }
    std::cout << start << " -> " << i << "   " << dist[i]->priority << std::endl;
    min = dist[i]->priority;
    delete dist[i];
  }
  delete[]dist;
  delete q;
  return min;
}

/*           Алгортм Дейкстры           */
/*        на красно-чёрных деревьях     */

int TreeDijkstra(std::vector < std::vector < std::pair<int, int> > > g, int start) {
  std::cout << std::endl;
  std::cout << "DIJKSTRA ALGORITHM ON RB TREE" << std::endl;
  // проверка корректности входных данных
  if (g.empty() || (start < 0) || (start > static_cast<int>(g.size())))
    throw std::logic_error("Input error: graph is empty or wrong start virtex.\n");

  // подготовка данных для работы алгоритма
  std::vector<int> dist(g.size(), INF);
  int v;
  dist[start] = 0;
  PriorityQueueRBtree < std::pair<int, int> > pq;
  pq.add(std::pair<int, int>(0, start));

  // алгоритм Дейкстры
  while (!pq.isEmpty()) {
    std::pair<int, int> current = pq.min()->value;
    pq.pop(current);
    v = current.second;
    for (int i = 0; i < static_cast<int>(g[v].size()); ++i) {
      if (dist[v] + g[v][i].second < dist[g[v][i].first]) {
        if (dist[g[v][i].first] != INF)
          pq.pop(std::pair<int, int>(dist[g[v][i].first],
            g[v][i].first));
        dist[g[v][i].first] = dist[v] + g[v][i].second;
        pq.add(std::pair<int, int>(dist[g[v][i].first], g[v][i].first));
      }
    }
  }

  // вывод (можно было реализовать воврат полученного d)
  std::cout << std::endl;
  int size = dist.size();
  for (int i = 0; i < size; i++) {
    if (i == start) {
      std::cout << "Start position: " << start << std::endl;
      continue;
    }
    std::cout << start << " -> " << i << "   " << dist[i] << std::endl;
  }
  int min = dist[size - 1];
  return min;
}

