#include <gtest/gtest.h>
#include <vector>
#include "Dijkstra.h"

TEST(Dijkstra, can_find_min_way_1) {
  int start = 0, end = 5;
  std::vector< std::vector<edge> > g =
  { { make_edge(0, 1, 1) },
  { make_edge(1, 2, 2), make_edge(1, 4, 8) },
  { make_edge(2, 3, 3) },
  { make_edge(3, 4, 5) },
  { make_edge(4, 5, 1) },
  { make_edge(5, -1, -1) } };
  EXPECT_EQ(Dijkstra(g, start, end), 10);
}

TEST(Dijkstra, can_find_min_way_2) {
  int start = 0, end = 5;
  std::vector< std::vector<edge> > g =
  { { make_edge(0, 1, 2), make_edge(0, 5, 10) },
  { make_edge(1, 2, 1), make_edge(1, 4, 5) },
  { make_edge(2, 3, 1) },
  { make_edge(3, 4, 1) },
  { make_edge(4, 5, 1) },
  { make_edge(5, -1, -1) } };
  EXPECT_EQ(Dijkstra(g, start, end), 6);
}

TEST(Dijkstra, can_find_min_way_3) {
  int start = 0, end = 5;
  std::vector< std::vector<edge> > g =
  { { make_edge(0, 1, 2), make_edge(0, 5, 6) },
  { make_edge(1, 2, 1), make_edge(1, 4, 5) },
  { make_edge(2, 3, 1) },
  { make_edge(3, 4, 1) },
  { make_edge(4, 5, 1) },
  { make_edge(5, -1, -1) } };
  EXPECT_EQ(Dijkstra(g, start, end), 6);
}


TEST(Dijkstra, can_find_min_way_4) {
  int start = 0, end = 2;
  std::vector< std::vector<edge> > g =
  { { make_edge(0, 1, 1), make_edge(0, 2, 3) },
  { make_edge(1, 2, 5)},
  { make_edge(2, -1, -1) } };
  EXPECT_EQ(Dijkstra(g, start, end), 3);
}

TEST(Dijkstra, can_work_with_graph_of_one_element) {
  int start = 2, end = 2;
  std::vector< std::vector<edge> > g =
  { {make_edge(2, -1, -1)} };
  EXPECT_EQ(Dijkstra(g, start, end), 0);
}

TEST(Dijkstra, can_work_with_throw_for_graph_of_one_element_1) {
  int start = 2, end = 2;
  std::vector< std::vector<edge> > g =
  { { make_edge(1, -1, -1) } };
  EXPECT_ANY_THROW(Dijkstra(g, start, end));
}

TEST(Dijkstra, can_work_with_throw_for_graph_of_one_element_2) {
  int start = 0, end = 0;
  std::vector< std::vector<edge> > g;
  EXPECT_ANY_THROW(Dijkstra(g, start, end));
}
