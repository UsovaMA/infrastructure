/*         Построение минимального остовного дерева графа       */
/*                         Алгоритм Прима                       */
/*     Вход: граф построенный по матрице смежности из файла     */
/* Выход: Пары вершин, составляющих минимальное остовное дерево */

#include "prim.h"
#include <stdexcept>

using std::logic_error;

void Prim(Graph* graph, Graph* ostov) {
  int verices = graph->N;
  int edge_N = graph->edge_N;
  edge* edges = graph->edges;
  if (!verices)
    throw logic_error("Error: there in not verix in graph.\n");
  if (!edge_N)
    throw logic_error("Error: there in not edges in graph.\n");

  // подготовка данных для работы алгоритма
  ostov->N = verices;
  ostov->edge_N = verices - 1;
  ostov->edges = new edge[verices - 1];
  Data** keys = new Data*[verices];
  // int* parent = new int[verices];
  for (int i = 0; i < verices; i++) {
    // parent[i] = -1;
    keys[i] = new Prim_Data(i, INF);
  }
  PriorityQueue* pq = new PriorityQueue(4);
  std::vector<bool> inMST(verices, false);
  keys[0]->priority = 0;
  pq->add(&keys[0]);

  // алгоритм Прима
  while (!pq->isEmpty()) {
    // находим минимальное ребро вершины
    int u = (reinterpret_cast<Prim_Data*>(pq->pop_min()))->ver;
    inMST[u] = true;  // включаем вершину в остов

    for (int i = 0; i < edge_N; ++i) {
      edge p = edges[i];
      edge tmp;
      int v1 = static_cast<int>(p.x) - 65;
      int v2 = static_cast<int>(p.y) - 65;
      int weight = p.weight;
      // добавляем рёбра выбранной вершины
      if ((v1 == u) || (v2 == u)) {
        if ((inMST[v1] == false) && (keys[v1]->priority > weight)) {
          keys[v1]->priority = weight;
          pq->add(&keys[v1]);
          // parent[v1] = u;
          tmp.x = u + 65;
          tmp.y = v1 + 65;
          tmp.weight = weight;
          ostov->edges[v1-1] = tmp;
        } else {
          if ((inMST[v2] == false) && (keys[v2]->priority > weight)) {
            keys[v2]->priority = weight;
            pq->add(&keys[v2]);
            // parent[v2] = u;
            tmp.x = u + 65;
            tmp.y = v2 + 65;
            tmp.weight = weight;
            ostov->edges[v2-1] = tmp;
          }
        }
      }
    }
  }
  // вывод рёбер остовного дерева
  /*for (int i = 1; i < verices; ++i)
    printf("%c - %c\n", (char)(parent[i]+65), (char)(i+65));*/
  /*for (int i = 0; i < verices - 1; ++i)
    printf("%c - %c: %d\n", (ostov->edges[i]).x, (ostov->edges[i]).y, (ostov->edges[i]).weight);*/
}
