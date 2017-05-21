#include "building.h"

/* Конструктор */
Disjoint_Sets::Disjoint_Sets(int _size) {
  if (_size < 0)
    throw std::logic_error("Input Error: wrong size. Size must be > 0.\n");
  size = _size;
  parent = new int[size];
  rank = new int[size];
  for (int i = 0; i < size; i++) {
    parent[i] = i;
    rank[i] = 1;
  }
}

/* Деструктор */
Disjoint_Sets::~Disjoint_Sets() {
  delete[]parent;
  delete[]rank;
}

/* Создание для него множество размера 1 из самого себя */
void Disjoint_Sets::make_set(int x) {
  if (x < 0 || (x-1) > size)
    throw std::logic_error("Input Error: wrong parameter.\n");
  if (parent[x] != -1)
    throw std::logic_error("Input Error: wrong parameter.\n");
  parent[x] = x;
  rank[x] = 0;
}

/* Поиск множества, которому принадлежит элемент */
int Disjoint_Sets::find_set(int x) {
  if (x < 0 || (x - 1) > size) {
    throw std::logic_error("Input Error: wrong parameter.\n");
  } else {
    x = parent[x];
    while (parent[x] != x) {
      x = parent[x];
    }
    return x;
  }
}

/* Объединение множеств */
void Disjoint_Sets::union_sets(int x, int y) {
  if (x < 0 || (x - 1) > size || y < 0 || (y - 1) > size) {
    throw std::logic_error("Input Error: wrong parameter.\n");
  } else {
    int _x, _y;
    _x = find_set(x);
    _y = find_set(y);
    if (rank[_x] > rank[_y]) {
      ++rank[_x];
      parent[_y] = parent[_x];
    } else {
      ++rank[_y];
      parent[_x] = parent[_y];
    }
  }
}

/* Построение групп с учётом врагов */
std::vector < int > built_groups(std::vector <std::pair <int, int> > enemies, int n) {
  int size = enemies.size(); 
  Disjoint_Sets groups(n);
  int x, y;
  bool they_are_friends;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      x = groups.find_set(i);
      y = groups.find_set(j);
      they_are_friends = true;
      for (int k = 0; k < size; k++) {
        if (((groups.find_set(enemies[k].first) == x) &&
          (groups.find_set(enemies[k].second) == y))
          || ((groups.find_set(enemies[k].first) == y) &&
          (groups.find_set(enemies[k].second) == x))) {
          they_are_friends = false;
          break;
        }
      }
      if (they_are_friends)
        groups.union_sets(x, y);
    }
  }
  std::vector < int > result;
  for (int i = 0; i < n; i++)
    result.push_back(groups.find_set(i));
  return result;
}
