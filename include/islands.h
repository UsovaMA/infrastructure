#ifndef INCLUDE_ISLANDS_H_
#define INCLUDE_ISLANDS_H_
#include <vector>

struct index {
  int line;
  int column;
};

int find_set(std::vector<int> a, int x);
void union_sets(std::vector<int> *a, std::vector<int> *b, int x, int y);
void BFS(std::vector<std::vector<int>> matrix,
  std::vector<std::vector<int>> *field, index y);

std::vector<std::vector<int>> PercolationForDS(std::vector<std::vector<int>> m);
std::vector<std::vector<int>> PercolationForBFS(std::vector<std::vector<int>> m);

#endif  // INCLUDE_ISLANDS_H_
