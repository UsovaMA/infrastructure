#include <stdlib.h>
#include <vector>
#include <queue>
#include "islands.h"
#include <limits>
int inf = std::numeric_limits<int>::infinity();

/* Метод поиска для класса Разделённые множества */
int find_set(std::vector<int> a, int x) {
  int tmp = x;
  while (a[tmp] != tmp)
    tmp = a[tmp];
  return tmp;
}

/* Метод объединения для класса Разделенные множества */
void union_sets(std::vector<int> *a, std::vector<int> *b, int x, int y) {
  if ((*b)[find_set(*a, x)] > (*b)[find_set(*a, y)]) {
    (*a)[find_set(*a, y)] = (*a)[find_set(*a, x)];
    (*b)[find_set(*a, x)]++;
  } else {
    (*a)[find_set(*a, x)] = (*a)[find_set(*a, y)];
    (*b)[find_set(*a, y)]++;
  }
}

/* Затопление островов, реализованное на классе Разделённые множества */
std::vector<std::vector<int>> PercolationForDS
  (std::vector<std::vector<int>> matrix) {
  int matrix_size = matrix.size();
  int N = matrix_size * matrix_size + 2;
  std::vector<int> a(N);
  std::vector<int> b(N, 1);

  for (int i = 0; i < N; ++i)
    a[i] = i;

  for (int i = 0; i < matrix_size; ++i)
    if (matrix[0][i]) union_sets(&a, &b, 0, i + 1);

  for (int i = 0; i < matrix_size - 1; ++i) {
    for (int j = 0; j < matrix_size - 1; ++j) {
      if (matrix[i][j] && matrix[i][j + 1]) {
        union_sets(&a, &b, i * matrix_size + j + 1, i * matrix_size + j + 2);
      }
      if (matrix[i][j] && matrix[i + 1][j]) {
        union_sets(&a, &b, i * matrix_size + j + 1, (i + 1) * matrix_size + j + 1);
      }
    }
    if (matrix[i][matrix_size - 1] && matrix[i + 1][matrix_size - 1]) {
      union_sets(&a, &b, i * matrix_size + matrix_size, (i + 1) * matrix_size + matrix_size);
    }
  }

  for (int i = 0; i < matrix_size - 1; ++i)
    if (matrix[matrix_size - 1][i] && matrix[matrix_size - 1][i + 1]) {
      union_sets(&a, &b, (matrix_size - 1) * matrix_size + i + 1,
        (matrix_size - 1) * matrix_size + i + 2);
    }

  for (int i = 0; i < matrix_size; ++i)
    if (matrix[matrix_size - 1][i]) {
      union_sets(&a, &b, N - 1, (matrix_size - 1) * matrix_size + i + 1);
    }

  a.push_back(N);
  a.push_back(N + 1);
  b.push_back(1);
  b.push_back(1);

  for (int i = 0; i < matrix_size; ++i)
    if (matrix[i][0]) {
      union_sets(&a, &b, N, i * matrix_size + 1);
    }
  for (int i = 0; i < matrix_size; ++i)
    if (matrix[i][matrix_size - 1]) {
      union_sets(&a, &b, N + 1, i * matrix_size + matrix_size);
    }

  union_sets(&a, &b, 0, N - 1);
  union_sets(&a, &b, 0, N);
  union_sets(&a, &b, 0, N + 1);

  for (int i = 0; i < matrix_size - 1; ++i)
    for (int j = 0; j < matrix_size - 1; ++j)
      if (find_set(a, i * matrix_size + j + 1) != find_set(a, 0)) {
        matrix[i][j] = 0;
      }

  return matrix;
}

/* Обход в ширину (breadth-first search) */
void BFS(std::vector<std::vector<int>> matrix,
  std::vector<std::vector<int>> *field, index Y) {

  int matrix_size = matrix.size();
  std::queue<index> q;
  q.push(Y);
  (*field)[Y.line][Y.column] = 1;
  while (!q.empty()) {
    index point = q.front();
    q.pop();
    if (point.column > 0) {
      if ((matrix[point.line][point.column - 1] == 1) &&
        ((*field)[point.line][point.column - 1] == inf)) {
        (*field)[point.line][point.column - 1] = 1;
        index* temp = new index;
        temp->line = point.line;
        temp->column = point.column - 1;
        q.push(*temp);
      }
    }
    if (point.line > 0) {
      if ((matrix[point.line - 1][point.column] == 1) &&
        ((*field)[point.line - 1][point.column] == inf)) {
        (*field)[point.line - 1][point.column] = 1;
        index* temp = new index;
        temp->line = point.line - 1;
        temp->column = point.column;
        q.push(*temp);
      }
    }
    if (point.column + 1 < matrix_size) {
      if ((matrix[point.line][point.column + 1] == 1) &&
        ((*field)[point.line][point.column + 1] == inf)) {
        (*field)[point.line][point.column + 1] = 1;
        index* temp = new index;
        temp->line = point.line;
        temp->column = point.column + 1;
        q.push(*temp);
      }
    }
    if (point.line + 1 < matrix_size) {
      if ((matrix[point.line + 1][point.column] == 1) &&
        ((*field)[point.line + 1][point.column] == inf)) {
        (*field)[point.line + 1][point.column] = 1;
        index* temp = new index;
        temp->line = point.line + 1;
        temp->column = point.column;
        q.push(*temp);
      }
    }
  }
}

/* Затопление островов через обход в ширину (breadth-first search) */
std::vector<std::vector<int>> PercolationForBFS
  (std::vector<std::vector<int>> matrix) {
  int matrix_size = matrix.size();
  std::vector<std::vector<int>> field(matrix_size, std::vector<int>(matrix_size, inf));
  index Y;
  Y.line = 0;
  for (Y.column = 0; Y.column < matrix_size; ++Y.column) {
    if (matrix[Y.line][Y.column] == 1) BFS(matrix, &field, Y);
  }
  Y.line = matrix_size - 1;
  for (Y.column = 0; Y.column < matrix_size; ++Y.column) {
    if (matrix[Y.line][Y.column] == 1) BFS(matrix, &field, Y);
  }
  Y.column = 0;
  for (Y.line = 0; Y.line < matrix_size; ++Y.line) {
    if (matrix[Y.line][Y.column] == 1) BFS(matrix, &field, Y);
  }
  Y.column = matrix_size - 1;
  for (Y.line = 0; Y.line < matrix_size; ++Y.line) {
    if (matrix[Y.line][Y.column] == 1) BFS(matrix, &field, Y);
  }

  for (int i = 1; i < matrix_size - 1; ++i)
    for (int j = 1; j < matrix_size - 1; ++j)
      if (field[i][j] == inf) matrix[i][j] = 0;
  return matrix;
}
