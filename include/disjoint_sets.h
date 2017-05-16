#ifndef INCLUDE_DISJOINT_SETS_H_
#define INCLUDE_DISJOINT_SETS_H_

class Disjoint_Sets {
 public:
  int size;
  int *parent;
  int *rank;

  explicit Disjoint_Sets(int _size);
  ~Disjoint_Sets();
  void make_set(int x);
  void union_sets(int x, int y);
  int find_set(int x);
  void clear();
};

#endif  // INCLUDE_DISJOINT_SETS_H_
