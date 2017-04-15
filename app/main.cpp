#include <iostream>
#include <ctime>
#include "massive.h"

using std::cout;
using std::endl;

int main() {
  srand(time(0));
  int const N = 7;
  int* a = new int[N];
  int* result = new int[N];

  cout << "Source array:" << endl;
  for (int i = 0; i < N; i++)
    a[i] = rand() % 10;
  for (int i = 0; i < N; i++)
    cout << a[i] << " ";

  cout << "\nArray of products except the current elements:" << endl;
  result = made_massive(a, N);
  for (int i = 0; i < N; ++i)
    cout << result[i] << " ";
}
