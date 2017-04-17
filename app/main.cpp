#include "percolation.h"
#include <iostream>
#include <iomanip>  

int main() {
  int k = 100;
  int n = 3;
  int size = n * n + 2 * n;
  Disjoint_Sets A(size);
  int count;
  double result = 0;
  // проводим k экспериментов
  for (int i = 0; i < k; i++) {
    // подготавливаем множество для эксперимента
    A.clear();
    for (int i = 0; i < n; i++) {
      A.make_set(i);
      A.make_set(A.size - i - 1);
    }
    for (int i = 1; i < n; i++) {
      A.union_sets(0, i);
      A.union_sets(A.size - 1, A.size - i - 1);
    }
    count = 0;
    // эксперимент
    percolation(&A, n, count);
    result += count * 1.0;
  }
  // вычисляем математическое ожидание
  // result = result / (n * n) / k;
  std::cout << "Expected value: " << std::setprecision(5) << result / (n * n) / k << "\n";
}
