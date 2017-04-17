#ifndef INCLUDE_PERCOLATION_H_
#define INCLUDE_PERCOLATION_H_

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

int percolation(Disjoint_Sets *a, int n);

#endif  // INCLUDE_PERCOLATION_H_
