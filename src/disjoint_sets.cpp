#include "disjoint_sets.h"
#include <iostream>
#include <stdexcept>

using std::logic_error;

/* ����������� */
Disjoint_Sets::Disjoint_Sets(int _size) {
  if (_size < 0)
    throw logic_error("Input Error: wrong size. Size must be > 0.\n");
  size = _size;
  parent = new int[size];
  rank = new int[size];
  for (int i = 0; i < size; i++) {
    parent[i] = -1;
    rank[i] = -1;
  }
}

/* ���������� */
Disjoint_Sets::~Disjoint_Sets() {
  delete[]parent;
  delete[]rank;
}

/* �������� ��� ���� ��������� ������� 1 �� ������ ���� */
void Disjoint_Sets::make_set(int x) {
  if (x < 0 || x > size)
    throw logic_error("Input Error: wrong parameter.\n");
  if (parent[x] != -1)
    throw logic_error("Input Error: wrong parameter.\n");
  parent[x] = x;
  rank[x] = 0;
}

/* ����� ���������, �������� ����������� ������� */
int Disjoint_Sets::find_set(int x) {
  if (x < 0 || x > size)
    throw logic_error("Input Error: wrong parameter.\n");
  if (parent[x] == -1)
    throw logic_error("Input Error: wrong parameter.\n");
  while (parent[x] != x)
    x = parent[x];
  return parent[x];
}

/* ����������� �������� */
void Disjoint_Sets::union_sets(int x, int y) {
  if (x < 0 || x > size || y < 0 || y > size)
    throw logic_error("Input Error: wrong parameter.\n");
  if (parent[x] == -1 || parent[y] == -1)
    throw logic_error("Input Error: wrong parameter.\n");
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

/* ������� ��������� ��� ������������� */
void Disjoint_Sets::clear() {
  for (int i = 0; i < size; i++) {
    parent[i] = -1;
    rank[i] = -1;
  }
}
