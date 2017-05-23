#include <gtest/gtest.h>
#include "RBtree.h"

/*TEST(RBTree, can_create_empty_tree) {
  ASSERT_NO_THROW(RBTree<int> a());
  RBTree<int> b;
  EXPECT_EQ(b.get_root(), NullNode);
}*/

/*TEST(RB_TREE, can_create_tree) {
  ASSERT_NO_THROW(RBTree<int> tree(5));
}*/

TEST(RB_TREE, create_tree_correctly) {
  RBTree<int> tree(5);
  int res = tree.get_root()->value;
  EXPECT_EQ(res , 5);
}

/*TEST(RB_TREE, can_insert) {
  RBTree<int> tree(5);
  ASSERT_NO_THROW(tree.RB_insert(3));
}*/

/*TEST(RB_TREE, can_insert_node_in_empty_tree) {
  RBTree<int> tree;
  ASSERT_NO_THROW(tree.RB_insert(1));
}*/

/*TEST(RB_TREE, throw_when_try_insert_exist_node) {
  RBTree<int> tree(5);
  ASSERT_ANY_THROW(tree.RB_insert(5));
}*/

TEST(RB_TREE, can_find_node) {
  RBTree<int> tree(5);
  tree.RB_insert(1);
  ASSERT_NO_THROW(tree.RB_find(1));
}

TEST(RB_TREE, find_node_correctly) {
  RBTree<int> tree(5);
  tree.RB_insert(4);
  RBtreeNode<int> *result = tree.RB_find(4);
  EXPECT_EQ(result->value, 4);
}

TEST(RB_TREE, throw_when_try_find_dont_exist_node) {
  RBTree<int> tree(5);
  tree.RB_insert(1);
  ASSERT_ANY_THROW(tree.RB_find(3));
}

TEST(RB_TREE, can_insert_2) {
  RBTree<int> tree(8);
  tree.RB_insert(7);
  ASSERT_NO_THROW(tree.RB_insert(2));
  ASSERT_NO_THROW(tree.RB_insert(5));
  ASSERT_NO_THROW(tree.RB_insert(1));
  ASSERT_NO_THROW(tree.RB_insert(3));
  ASSERT_NO_THROW(tree.RB_insert(4));
  ASSERT_NO_THROW(tree.RB_insert(9));
  ASSERT_NO_THROW(tree.RB_find(4));
}

TEST(RB_TREE, throw_when_try_delete_dont_exist_node) {
  RBTree<int> tree(5);
  tree.RB_insert(2);
  ASSERT_ANY_THROW(tree.RB_delete(3));
}

TEST(RB_TREE, can_delete_node_with_no_childs) {
  RBTree<int> tree(5);
  tree.RB_insert(2);
  ASSERT_NO_THROW(tree.RB_delete(2));
}

TEST(RB_TREE, can_delete_node_with_child) {
  RBTree<int> tree(6);
  tree.RB_insert(3);
  ASSERT_NO_THROW(tree.RB_insert(5));
  ASSERT_NO_THROW(tree.RB_insert(1));
  ASSERT_NO_THROW(tree.RB_insert(4));
  ASSERT_NO_THROW(tree.RB_insert(2));
  ASSERT_NO_THROW(tree.RB_find(5));
  ASSERT_NO_THROW(tree.RB_delete(5));
  ASSERT_ANY_THROW(tree.RB_find(5));
}
