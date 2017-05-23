#ifndef INCLUDE_D_HEAP_H_
#define INCLUDE_D_HEAP_H_

#include <iostream>
#define MAXsize 1000

struct Data {
  int priority;
};

class D_Heap {
 protected:
  Data **key;
  int d;
  int size;

 public:
  explicit D_Heap(int d);
  D_Heap(const D_Heap &heap);
  ~D_Heap();

  int Child(int i);
  int Parent(int i);
  int isFull();
  int isEmpty();

  void insert(Data **i);
  void insert_group(Data **keys, int num);
  Data* erase();
  Data* erase(int i);
  void transposition(int i, int j);
  void surfacing(int i);
  void immersion(int i);
  void hilling();

  int min_Child(int i);
};

#endif  // INCLUDE_D_HEAP_H_
