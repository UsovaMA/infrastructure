#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include <vector>
#include <iostream>
#include <ctime>
#define MAXver 1000

/* Рёбра графа */
class Edges {
 public:
  int x;
  int y;
  int weight;
  Edges(int _x, int _y, int _w) {
    this->x = _x;
    this->y = _y;
    this->weight = _w;
  }
};

class Graph {
 private:
  int verices;
  int edge;
  int size;
  int* ver_mas;
  Edges** edge_mas;

 public:
  explicit Graph(int _ver);
  Graph(int _ver, int _edge);
  ~Graph();

  int get_ver();
  int get_edge_num();
  int get_size();
  int get_weight(int _x, int _y);
  Edges* get_edge(int i);
  Edges** get_edge_mas();

  int isFull();
  int isEmpty();

  void create_ver(int *x, int *y);
  void create_graph(int min_w, int max_w);
  void insert_edge(int _x, int _y, int _w);
  void delete_edge(int _x, int _y);
  int find_edge_num(int _x, int _y);
};

std::vector < std::vector < std::pair<int, int> > > make_graph(char filename[]);

#endif  // INCLUDE_GRAPH_H_
