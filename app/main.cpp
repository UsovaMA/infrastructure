#include "islands.h"
#include <iostream>
#include <time.h>

int main() {
  srand(time(NULL));
  std::vector<std::vector<int>> m(8, std::vector<int>(8, 0));

  std::cout << "Map:" << std::endl;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (rand() % 2 == 0) {
        m[i][j] = 0;
      } else {
        m[i][j] = 1;
      }
      std::cout << m[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Map after DS method:" << std::endl;
  std::vector<std::vector<int>> res1 = PercolationForDS(m);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      std::cout << res1[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Map after BFS method:" << std::endl;
  std::vector<std::vector<int>> res2 = PercolationForBFS(m);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      std::cout << res2[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
