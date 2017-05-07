#include <iostream>
#include "graph.h"
#include <stdexcept>

using std::logic_error;

/* Добавление ребра */
void make_edge(char _x, char _y, int _weight, edge* r) {
  if (_x == _y)
    throw logic_error("Error: same verix.\n");
  r->x = _x;
  r->y = _y;
  r->weight = _weight;
}

/* Создание графа */
void make_graph(int node, int edgee, edge* r, Graph *g) {
  if (node < 0)
    throw logic_error("Error: number of verices can't be < 0.\n");
  if (edgee < 0)
    throw logic_error("Error: number of edges can't be < 0.\n");
  g->edge_N = edgee;
  g->N = node;
  g->edges = new edge[edgee];
  for (int i = 0; i < edgee; i++)
    g->edges[i] = r[i];
  for (int i = 0; i < edgee; i++)
    for (int j = edgee - 1; j > i; j--)
      if (g->edges[j - 1].weight < g->edges[j].weight) {
        edge tmp = g->edges[j - 1];
        g->edges[j - 1] = g->edges[j];
        g->edges[j] = tmp;
      }
}

/* Вывод графа */
void Print(Graph *g) {
  for (int i = 0; i < g->edge_N; i++)
    std::cout << g->edges[i].x << " - " << g->edges[i].y << "; \n";
}

/* Чтение матрицы смежности из файла и создание графа */
Graph Create_graph(char *q) {
  pInt *W;  // матрица смежности
  Graph g;  // граф
  FILE *F;
  int N = 0, edge_N = 0;
  F = fopen(q, "r");
  if (F == NULL) {
    throw logic_error("Input error. Can't open this file.\n");
  }
  // считывание количества вершин графа
  fscanf(F, "%d", &N);

  W = reinterpret_cast<pInt*>(calloc(N, sizeof(pInt)));
  for (int i = 0; i < N; i++)
    W[i] = reinterpret_cast<int*>(calloc(N, sizeof(int)));

  // вывод матрицы смежности
  std::cout << "Matrix of adjacency of the graph:" << std::endl << std::endl;
  std::cout << "    ";
  for (int i = 0; i < N; i++)
    printf("%4c", ASCII[i]);
  std::cout << "" << std::endl;
  std::cout << "----";
  for (int i = 0; i < N; i++)
    std::cout << "----";
  std::cout << "" << std::endl;

  for (int i = 0; i < N; i++) {
    printf("%2c |", ASCII[i]);
    for (int j = 0; j < N; j++) {
      fscanf(F, "%d", &W[i][j]);
      if (W[i][j] <= 0) {
        W[i][j] = inf;
        std::cout << "   -";
      } else {
        edge_N++;
        printf("%4d", W[i][j]);
      }
    }
    std::cout << "" << std::endl;
  }

  edge_N = edge_N / 2;
  fclose(F);

  std::cout << "" << std::endl;
  int a = 0;

  // создание рёбер по матрице смежности
  edge r;
  edge* e = new edge[edge_N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if ((W[i][j] != inf) && (i < j)) {
        make_edge(ASCII[i], ASCII[j], W[i][j], &r);
        e[a] = r;
        a++;
      }
  // создание графа
  make_graph(N, edge_N, e, &g);
  return g;
}

/* Чтение списка смежности из файла и создание графа */
Graph create_graph(char *q) {
  Graph g;  // граф
  FILE *F;
  int N = 0, edge_N = 0;
  F = fopen(q, "r");
  if (F == NULL) {
    throw logic_error("Input error. Can't open this file.\n");
  }
  // считывание количества вершин графа
  fscanf(F, "%d", &N);
  // считывание количества рёбер графа
  fscanf(F, "%d", &edge_N);

  int tmp = 0;
  std::cout << "" << std::endl;

  // вывод списка смежности
  std::cout << "List of adjacency of the graph:" << std::endl;
  int num, ch, a = 0;
  edge r;
  edge* e = new edge[edge_N];
  for (int i = 0; i < N; i++) {
    std::cout << "" << std::endl;
    printf("%2c :", ASCII[i]);
    fscanf(F, "%d", &num);
    for (int j = 0; j < num; j++) {
      fscanf(F, "%d", &tmp);
      ch = tmp + 65;
      printf("%4c", tmp + 65);
      fscanf(F, "%d", &tmp);
      printf("%4d", tmp);
      if ((i + 65) < ch) {
        make_edge(ASCII[i], ch, tmp, &r);
        e[a] = r;
        a++;
      }
    }
  }
  std::cout << "" << std::endl << std::endl;
  fclose(F);
  // создание графа
  make_graph(N, edge_N, e, &g);
  return g;
}
