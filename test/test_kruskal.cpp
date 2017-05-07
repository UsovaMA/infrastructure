#include <gtest/gtest.h>
#include "kruskal.h"

TEST(KRUSKALS_ALG, kruskals_alg_can_work_correctly) {
  Graph g;
  Graph ostov;
  edge r;
  edge* e = new edge[8];
  make_edge('A', 'B', 1, &r);
  e[0] = r;
  make_edge('A', 'C', 3, &r);
  e[1] = r;
  make_edge('A', 'D', 3, &r);
  e[2] = r;
  make_edge('C', 'B', 2, &r);
  e[3] = r;
  make_edge('E', 'B', 8, &r);
  e[4] = r;
  make_edge('D', 'E', 4, &r);
  e[5] = r;
  make_edge('C', 'E', 3, &r);
  e[6] = r;
  make_edge('D', 'C', 1, &r);
  e[7] = r;
  make_graph(5, 8, e, &g);
  int sum = 0;
  Kruskal(&g, &ostov);
  for (int i = 0; i < 4; ++i)
    sum += (ostov.edges[i]).weight;
  EXPECT_EQ(sum, 7);
  EXPECT_EQ(ostov.edge_N, 4);
  EXPECT_EQ(ostov.N, 5);
}

TEST(KRUSKALS_ALG, kruskals_alg_can_work_with_one_edge) {
  Graph g;
  Graph ostov;
  edge r;
  edge* e = new edge[1];
  make_edge('A', 'B', 1, &r);
  e[0] = r;
  make_graph(2, 1, e, &g);
  int sum = 0;
  Kruskal(&g, &ostov);
  for (int i = 0; i < 1; ++i)
    sum += (ostov.edges[i]).weight;
  EXPECT_EQ(sum, 1);
  EXPECT_EQ(ostov.edge_N, 1);
  EXPECT_EQ(ostov.N, 2);
}

/*TEST(KRUSKALS_ALG, throw_when_try_kruskals_alg_with_wrong_parameters_1) {
  Graph g;
  Graph ostov;
  edge* e;
  g.edge_N = 0;
  g.N = 2;
  g.edges = nullptr;
  EXPECT_ANY_THROW(Kruskal(&g, &ostov));
}*/

/*TEST(KRUSKALS_ALG, throw_when_try_kruskals_alg_with_wrong_parameters_2) {
  Graph g;
  Graph ostov;
  EXPECT_ANY_THROW(Kruskal(&g, &ostov));
}*/
