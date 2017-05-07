#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_
#include <limits>

const char ASCII[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int inf = std::numeric_limits<int>::infinity();
typedef int *pInt;

struct edge {
  char x;
  char y;
  int weight;
};

struct Graph {
  int N;
  int edge_N;
  edge* edges;
};

void make_edge(char, char, int, edge*);
void make_graph(int, int, edge*, Graph*);
Graph Create_graph(char *q);
Graph create_graph(char *q);
void Print(Graph *g);

#endif  // INCLUDE_GRAPH_H_
