#include "min_way.h"
#include <queue>
#include <iostream>
#include <limits>

char* way(int x, int y) {
  char* a = new char[100];
  int x0 = 0, y0 = 0;
  int step = 1;

  if ((x == 0) && (y == 0)) {
    std::cout << "You are already in finish position";
  }

  if (x > 0) {
    while (x0 + step < x) {
      x0 += step;
      a[step - 1] = 'E';
      ++step;
    }
    while (x0 != x) {
      x0 -= step;
      a[step - 1] = 'W';
      ++step;
      x0 += step;
      a[step - 1] = 'E';
      ++step;
    }
  } else {
    while (x0 - step > x) {
      x0 -= step;
      a[step - 1] = 'W';
      ++step;
    }
    while (x0 != x) {
      x0 += step;
      a[step - 1] = 'E';
      ++step;
      x0 -= step;
      a[step - 1] = 'W';
      ++step;
    }
  }

  if (y > 0) {
    while (y0 + step < y) {
      y0 += step;
      a[step - 1] = 'N';
      ++step;
    }
    while (y0 != y) {
      y0 -= step;
      a[step - 1] = 'S';
      ++step;
      y0 += step;
      a[step - 1] = 'N';
      step++;
    }
  } else {
    while (y0 - step > y) {
      y0 -= step;
      a[step - 1] = 'S';
      ++step;
    }
    while (y0 != y) {
      y0 += step;
      a[step - 1] = 'N';
      ++step;
      y0 -= step;
      a[step - 1] = 'S';
      ++step;
    }
  }
  a[step - 1] = '\0';
  return a;
}
