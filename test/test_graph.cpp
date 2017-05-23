#include <gtest/gtest.h>
#include "graph.h"

/*TEST(GRAPH, can_create_graph_1) {
  Graph *graph;
  ASSERT_NO_THROW(graph = new Graph(2));
}*/

/*TEST(GRAPH, can_create_graph_2) {
  Graph *graph;
  ASSERT_NO_THROW(graph = new Graph(2, 1));
}*/

/*TEST(GRAPH, can_create_graph) {
  Graph *graph = new Graph(2);
  ASSERT_NO_THROW(graph->create_graph(3, 7));
}*/

/*TEST(GRAPH, can_insert_edge) {
  Graph *graph = new Graph(2);
  ASSERT_NO_THROW(graph->insert_edge(0, 1, 2));
}*/

TEST(GRAPH, can_delete_edge) {
  Graph *graph = new Graph(2);
  graph->insert_edge(0, 1, 2);
  ASSERT_NO_THROW(graph->delete_edge(0, 1));
}

TEST(GRAPH, can_find_edge_num) {
  Graph *graph = new Graph(3);
  graph->insert_edge(0, 1, 2);
  graph->insert_edge(1, 2, 3);
  graph->insert_edge(2, 0, 4);
  ASSERT_NO_THROW(graph->find_edge_num(1, 2));
}


TEST(GRAPH, find_edge_num_work_correctly) {
  Graph *graph = new Graph(3);
  graph->insert_edge(0, 1, 2);
  graph->insert_edge(1, 2, 3);
  graph->insert_edge(2, 0, 4);
  EXPECT_EQ(1, graph->find_edge_num(1, 2));
}

/*TEST(GRAPH, get_ver_work_correctly) {
  Graph *graph = new Graph(2);
  EXPECT_EQ(2, graph->get_ver());
}*/

/*TEST(GRAPH, get_edge_num_work_correctly) {
  Graph *graph = new Graph(2);
  EXPECT_EQ(1, graph->get_edge_num());
}*/

TEST(GRAPH, get_size_work_correctly) {
  Graph *graph = new Graph(2);
  graph->insert_edge(0, 1, 2);
  EXPECT_EQ(1, graph->get_size());
}

TEST(GRAPH, get_weight_work_correctly) {
  Graph *graph = new Graph(2);
  graph->insert_edge(0, 1, 4);
  EXPECT_EQ(4, graph->get_weight(0, 1));
}

/*TEST(GRAPH, throw_when_try_create_graph_with_negative_verix) {
  Graph *graph;
  ASSERT_ANY_THROW(graph = new Graph(-2));
}*/

/*TEST(GRAPH, throw_when_try_create_graph_with_too_large_verix) {
  Graph *graph;
  ASSERT_ANY_THROW(graph = new Graph(MAXver + 1));
}*/

/*TEST(GRAPH, throw_when_try_create_graph_with_negative_edge) {
  Graph *graph;
  ASSERT_ANY_THROW(graph = new Graph(2, -1));
}*/

/*TEST(GRAPH, throw_when_try_create_graph_with_too_large_edge) {
  Graph *graph;
  ASSERT_ANY_THROW(graph = new Graph(2, 2));
}*/

/*TEST(GRAPH, throw_when_try_create_graph_with_wrong_weight_limitations) {
  Graph *graph = new Graph(2);
  ASSERT_ANY_THROW(graph->create_graph(5, 0));
}*/


/*TEST(GRAPH, throw_when_try_insert_edge_between_one_verix) {
  Graph *graph = new Graph(2);
  ASSERT_ANY_THROW(graph->insert_edge(1, 1, 2));
}*/

TEST(GRAPH, throw_when_try_insert_exist_edge) {
  Graph *graph = new Graph(2);
  graph->insert_edge(0, 1, 2);
  ASSERT_ANY_THROW(graph->insert_edge(0, 1, 2));
}

/*TEST(GRAPH, throw_when_try_delete_doesnt_exist_edge) {
  Graph *graph = new Graph(3);
  ASSERT_ANY_THROW(graph->delete_edge(0, 1));
}*/
