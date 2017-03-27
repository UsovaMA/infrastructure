#include "min_way.h"
#include <queue>
#include <iostream>
#include <limits>

char* way(int x, int y) {
  char* a = new char [100];
  int x0 = 0, y0 = 0;
  int step = 1;
  if ((x == 0) && (y == 0)) {
    throw std::logic_error("Error description\n"); 
  }
  while (x0 <= x) {
    x += step;
    a[step] = 'E';
    step++;
    y += step;
    a[step] = 'N';
    step++;
  }
  while (x0 != x) {
    if (x < x0) {
    x += step;
    a[step] = 'E';
    step++;
  }
    if (x > x0) {
      x -= step;
      a[step] = 'W';
      step++;
    }
  }
  while (y0 != y) {
    if (y < y0) {
      y += step;
      a[step] = 'N';
      step++;
    }
    if (y > x0) {
      y -= step;
      a[step] = 'S';
      step++;
    }
  }
}

bool test () {
  int x, y;
  int i = 5;
  char* a;
  while (i < 50) {
	  x = i;
	  y = i--;
	  a = way(x, y);
	  x = -i;
	  y = ++i;
	  a = way(x, y);
	  x = ++i;
	  y = -i;
	  a = way(x, y);
  }
  return true;
}
  