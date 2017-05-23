#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <stdexcept>

/* Конструкторы */
Graph::Graph(int _ver) {
  if (_ver < 0 || _ver > MAXver)
    throw std::logic_error("Input error: wrong vertices number.\n");
  this->verices = _ver;
  this->edge = _ver*(_ver - 1) / 2;
  size = 0;
  ver_mas = new int[_ver];
  edge_mas = new Edges*[edge];
}

Graph::Graph(int _ver, int _edge) {
  if (_ver < 0 || _ver > MAXver)
    throw std::logic_error("Input error: wrong vertices number.\n");
  if (_edge < 0 || _edge > _ver * (_ver - 1) / 2)
    throw std::logic_error("Input error: wrong edges number.\n");
  this->verices = _ver;
  this->edge = _edge;
  size = 0;
  ver_mas = new int[_ver];
  edge_mas = new Edges*[_edge];
}

/* Деструктор */
Graph::~Graph() {
  for (int i = 0; i < size; i++)
    delete edge_mas[i];
  delete[]edge_mas;
  delete[]ver_mas;
}

/* Функции возврата параметров графа*/

/* Количество вершин */
int Graph::get_ver() {
  return verices;
}

/* Число рёбер графа */
int Graph::get_edge_num() {
  return edge;
}

/* Размер графа */
int Graph::get_size() {
  return size;
}

/* Расстояние между двумя вершинами */
int Graph::get_weight(int _x, int _y) {
  int i = find_edge_num(_x, _y);
  return edge_mas[i]->weight;
}

/* Ребро */
Edges* Graph::get_edge(int i) {
  return edge_mas[i];
}

/* Массив рёбер */
Edges** Graph::get_edge_mas() {
  if (size == 0)
    return nullptr;
  return edge_mas;
}

int Graph::isFull() {
  return edge == size;
}

int Graph::isEmpty() {
  return size == 0;
}

/* Создание вершины */
void Graph::create_ver(int *x, int *y) {
  *x = rand() % verices;
  *y = rand() % verices;
  if (x == y || find_edge_num(*x, *y) != -1)
    create_ver(x, y);
}

/* Создание графа */
void Graph::create_graph(int min_w, int max_w) {
  if (min_w > max_w)
    throw std::logic_error("Input error: min must be < max.\n");
  int x_, y_, w_;
  for (int i = 0; i < edge; i++) {
    time_t  timet;
    time(&timet);
    srand(static_cast<int>(timet));
    create_ver(&x_, &y_);
    w_ = rand() % static_cast<int>(max_w - min_w + 1) + min_w;
    edge_mas[i] = new Edges(x_, y_, w_);
    size++;
  }
}

/* Добавление ребра */
void Graph::insert_edge(int _x, int _y, int _w) {
  if (isFull())
    throw std::logic_error("Graph is FULL.\n");
  if (find_edge_num(_x, _y) != -1)
    throw std::logic_error("Edge already exist.\n");
  if (_x == _y)
    throw std::logic_error("Input error: x = y.\n");
  edge_mas[size] = new Edges(_x, _y, _w);
  size++;
}

/* Удаление ребра */
void Graph::delete_edge(int _x, int _y) {
  int i = find_edge_num(_x, _y);
  if (i == -1)
    throw std::logic_error("Edge doesn't exist.\n");
  delete edge_mas[i];
  edge_mas[i] = edge_mas[size - 1];
  size--;
}

/* Номер ребра между вершинами в массиве рёбер */
int Graph::find_edge_num(int _x, int _y) {
  for (int i = 0; i < size; i++) {
    if ((edge_mas[i]->x == _x && edge_mas[i]->y == _y) ||
      (edge_mas[i]->x == _y && edge_mas[i]->y == _x))
      return i;
  }
  return -1;
}

/* Чтение из файла для графа на встроенных структурах*/
std::vector < std::vector < std::pair<int, int> > > make_graph(char filename[]) {
  std::ifstream file(filename);
  int N, n;
  // считываем число вершин
  file >> N;
  std::vector < std::vector < std::pair<int, int> > > g(N);
  // считываем рёбра
  for (int i = 0; i < N; ++i) {
    file >> n;
    g[i] = std::vector< std::pair<int, int>>(n);
    for (int j = 0; j < n; ++j) {
      file >> g[i][j].first >> g[i][j].second;
    }
  }
  return g;
}

/* Чтение из файла для реализованного графа*/
Graph create_graph(char *q) {
  FILE *F;
  int N = 0, edge_N = 0;
  F = fopen(q, "r");
  if (F == NULL) {
    throw std::logic_error("Input error. Can't open this file.\n");
  }
  // считывание количества вершин графа
  fscanf(F, "%d", &N);
  Graph g(N);  // граф

  int tmp, num, w;
  for (int i = 0; i < N; i++) {
    fscanf(F, "%d", &num);
    for (int j = 0; j < num; j++) {
      fscanf(F, "%d", &tmp);
      fscanf(F, "%d", &w);
      g.insert_edge(i, tmp, w);
    }
  }
  fclose(F);
  return g;
}
