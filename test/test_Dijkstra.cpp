#include "gtest/gtest.h"
#include "Dijkstra.h"
#include <vector>

/*TEST(DIJKSTRA, throw_when_try_work_without_vertices) {
  Graph *graph = new Graph(0);
  ASSERT_ANY_THROW(HeapDijkstra(&graph, 0));
}*/

TEST(DIJKSTRA, throw_when_try_work_with_wrong_start_vertex) {
  Graph *graph = new Graph(4);
  graph->insert_edge(0, 1, 2);
  ASSERT_ANY_THROW(HeapDijkstra(&graph, 9));
}

TEST(DIJKSTRA, experiment_1) {
  Graph *graph = new Graph(4);
  graph->insert_edge(0, 1, 1);
  graph->insert_edge(1, 2, 2);
  graph->insert_edge(2, 3, 2);
  graph->insert_edge(3, 0, 8);
  EXPECT_EQ(2, HeapDijkstra(&graph, 2));
  EXPECT_EQ(5, HeapDijkstra(&graph, 0));
}

TEST(DIJKSTRA, experiment_2) {
  Graph *graph = new Graph(4, 6);
  graph->insert_edge(0, 1, 1);
  graph->insert_edge(0, 2, 1);
  graph->insert_edge(0, 3, 8);
  graph->insert_edge(1, 2, 4);
  graph->insert_edge(1, 3, 6);
  graph->insert_edge(2, 3, 5);
  EXPECT_EQ(5, HeapDijkstra(&graph, 2));
  EXPECT_EQ(6, HeapDijkstra(&graph, 0));
}

TEST(DIJKSTRA, experiment_3) {
  Graph *graph = new Graph(8, 13);
  graph->insert_edge(0, 1, 3);
  graph->insert_edge(1, 2, 2);
  graph->insert_edge(1, 3, 4);
  graph->insert_edge(1, 4, 1);
  graph->insert_edge(2, 4, 3);
  graph->insert_edge(2, 5, 10);
  graph->insert_edge(3, 4, 2);
  graph->insert_edge(3, 6, 5);
  graph->insert_edge(4, 5, 7);
  graph->insert_edge(4, 6, 8);
  graph->insert_edge(4, 7, 4);
  graph->insert_edge(5, 7, 6);
  graph->insert_edge(6, 7, 1);
  EXPECT_EQ(8, HeapDijkstra(&graph, 0));
}

TEST(DIJKSTRA, experiment_4) {
  Graph *graph = new Graph(8, 13);
  graph->insert_edge(0, 1, 3);
  graph->insert_edge(1, 2, 1);
  graph->insert_edge(1, 3, 4);
  graph->insert_edge(1, 4, 1);
  graph->insert_edge(2, 4, 1);
  graph->insert_edge(2, 5, 10);
  graph->insert_edge(3, 4, 1);
  graph->insert_edge(3, 6, 1);
  graph->insert_edge(4, 5, 7);
  graph->insert_edge(4, 6, 8);
  graph->insert_edge(4, 7, 4);
  graph->insert_edge(5, 7, 6);
  graph->insert_edge(6, 7, 1);
  EXPECT_EQ(7, HeapDijkstra(&graph, 0));
}

TEST(DIJKSTRA, work_right_with_one_virtex) {
  std::vector < std::vector < std::pair<int, int> > > graph(1);
  int res = TreeDijkstra(graph, 0);
  EXPECT_EQ(res, 0);
}
