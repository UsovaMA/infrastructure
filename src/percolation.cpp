#include "percolation.h"
#include <iostream>
#include <ctime>

/* Конструктор */
Disjoint_Sets::Disjoint_Sets(int _size) {
  if (_size < 0)
    throw std::logic_error("Input Error: wrong size. Size must be > 0.\n");
  size = _size;
  parent = new int[size];
  rank = new int[size];
  for (int i = 0; i < size; i++) {
    parent[i] = -1;
    rank[i] = -1;
  }
}

/* Деструктор */
Disjoint_Sets::~Disjoint_Sets() {
  delete[]parent;
  delete[]rank;
}

/* Создание для него множество размера 1 из самого себя */
void Disjoint_Sets::make_set(int x) {
  if (x < 0 || x > size)
    throw std::logic_error("Input Error: wrong parameter.\n");
  if (parent[x] != -1)
    throw std::logic_error("Input Error: wrong parameter.\n");
  parent[x] = x;
  rank[x] = 0;
}

/* Поиск множества, которому принадлежит элемент */
int Disjoint_Sets::find_set(int x) {
  if (x < 0 || x > size)
    throw std::logic_error("Input Error: wrong parameter.\n");
  if (parent[x] == -1)
    throw std::logic_error("Input Error: wrong parameter.\n");
  while (parent[x] != x)
    x = parent[x];
  return parent[x];
}

/* Объединение множеств */
void Disjoint_Sets::union_sets(int x, int y) {
  if (x < 0 || x > size || y < 0 || y > size)
    throw std::logic_error("Input Error: wrong parameter.\n");
  if (parent[x] == -1 || parent[y] == -1)
    throw std::logic_error("Input Error: wrong parameter.\n");
  if (x != y) {
    int _x, _y;
    _x = find_set(x);
    _y = find_set(y);
    if (_x != _y) {
      if (rank[_x] < rank[_y]) {
        parent[_x] = _y;
      } else {
        parent[_y] = _x;
        if (rank[_x] == rank[_y])
          ++rank[_x];
      }
    }
  }
}

/* Очистка множества для экспериментов */
void Disjoint_Sets::clear() {
  for (int i = 0; i < size; i++) {
    parent[i] = -1;
    rank[i] = -1;
  }
}

/* Просачивание */
void percolation(Disjoint_Sets *set, int n, int &count) {
  int x, y;
  srand(time(NULL));
  int coordinate;
  bool flag = false;
  x = rand() % n;
  y = rand() % n;
  while (!flag && count < n * n) {
    // ставим рандомные точки в наше поле
    while ((*set).parent[x + (y + 1) * n] != -1) {
      x = rand() % n;
      y = rand() % n;
    }
    count++;
    coordinate = x + (y + 1) * n;
    (*set).make_set(coordinate);
    if (x > 0)
      if ((*set).parent[coordinate - 1] != -1)
        (*set).union_sets(coordinate, coordinate - 1);
    if ((*set).parent[coordinate - n] != -1)
      (*set).union_sets(coordinate, coordinate - n);
    if (x < n - 1)
      if ((*set).parent[coordinate + 1] != -1)
        (*set).union_sets(coordinate, coordinate + 1);
    if ((*set).parent[coordinate + n] != -1)
      (*set).union_sets(coordinate, coordinate + n);
    // проверяем, нашли ли мы путь
    // (начало и конец должны принадлежать одному множеству)
    flag = ((*set).find_set(0) == (*set).find_set((*set).size - 1));
  }
}
