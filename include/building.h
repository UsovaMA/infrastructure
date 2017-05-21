#ifndef INCLUDE_BUILDING_H_
#define INCLUDE_BUILDING_H_
#include <vector>
#include <stdexcept>

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
};

std::vector < int > built_groups(std::vector <std::pair <int, int> > enemies, int n);

#endif  // INCLUDE_BUILDING_H_
