#include "massive.h"
#include <iostream>

int*  made_massive(int* a, int N) {
  int* out = new int[N];
  int* tmp = new int[N - 1];
  int pr1 = 1, pr2 = 1, pr = 1;
  int zero = 0, index = 0;

  // empty massive
  if (N == 0)
    throw std::logic_error("Error description: empty massive.\n");

  // massive of 1 element
  if (N == 1) {
    out[0] = 1;
    return out;
  }

  for (int i = 0; i < N; i++) {
    if (a[i] == 0) {
      zero++;
      index = i;
    } else {
      pr *= a[i];
    }
  }

  // massive with 1 null-element
  if (zero == 1) {
    for (int i = 0; i < N; i++) {
      out[i] = 0;
    }
    out[index] = pr;
    return out;
  }

  // massive with null-elements
  if (zero > 1) {
    for (int i = 0; i < N; i++) {
      out[i] = 0;
    }
    return out;
  }

  for (int i = 0; i < N - 1; i++) {
    pr1 *= a[i];
    tmp[i] = pr1;
  }
  for (int j = N - 1; j > 0; j--) {
    out[j] = pr2 * tmp[j - 1];
    pr2 *= a[j];
  }
  out[0] = pr2;
  delete[] tmp;

  return out;
}
