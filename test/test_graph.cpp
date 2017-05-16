#include <gtest/gtest.h>
#include "graph.h"

TEST(GRAPH, can_make_edge) {
  edge e[3];
  edge r;
  ASSERT_NO_THROW(make_edge('A', 'B', 3, &r));
  e[0] = r;
}

TEST(GRAPH, can_make_graph_of_one_vertex) {
  Graph g;
  int N = 1;
  int edge_N = 0;
  edge* e = nullptr;
  ASSERT_NO_THROW(make_graph(N, edge_N, e, &g));
  make_graph(N, edge_N, e, &g);
}

TEST(GRAPH, can_make_graph) {
  Graph g;
  edge r;
  int N = 3;
  int edge_N = 2;
  edge* e = new edge[edge_N];
  for (int i = 0; i < edge_N; i++) {
    make_edge(ASCII[i], ASCII[i + 1], (i + 2) * 3, &r);
    e[i] = r;
  }
  ASSERT_NO_THROW(make_graph(N, edge_N, e, &g));
  make_graph(N, edge_N, e, &g);
}

TEST(GRAPH, throw_when_try_create_graph_with_negative_verix) {
  Graph g;
  int N = 1;
  int edge_N = 0;
  edge* e = nullptr;
  ASSERT_ANY_THROW(make_graph(-N, edge_N, e, &g));
  make_graph(N, edge_N, e, &g);
}

TEST(GRAPH, throw_when_try_create_graph_with_negative_edge) {
  Graph g;
  int N = 1;
  int edge_N = 0;
  edge* e = nullptr;
  ASSERT_ANY_THROW(make_graph(N, edge_N - 1, e, &g));
  make_graph(N, edge_N, e, &g);
}

TEST(GRAPH, throw_when_try_insert_edge_between_one_verix) {
  edge e;
  ASSERT_ANY_THROW(make_edge('A', 'A', 5, &e));
  make_edge('A', 'B', 5, &e);
}

TEST(GRAPH, can_work_when_try_insert_exist_edge) {
  edge e;
  make_edge('A', 'B', 5, &e);
  ASSERT_NO_THROW(make_edge('A', 'B', 5, &e));
}
