#ifndef INCLUDE_PRIM_H_
#define INCLUDE_PRIM_H_
#include "graph.h"
#include"d_heap.h"
#include <vector>

const int INF = 10000000;
class Prim_Data : public Data {
 public:
  int ver;
  Prim_Data(int ver, int weight) {
    this->ver = ver;
    priority = weight;
  }
};

void Prim(Graph*, Graph*);

#endif  // INCLUDE_PRIM_H_
