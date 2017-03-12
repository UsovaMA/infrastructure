#include <gtest/gtest.h>
#include "search_in_tree.h"

TEST(Find, can_find_medium_element) {
  CNode* tree = create_tree_for_tests();
  CNode** res = (find(&tree, 3));
  ASSERT_EQ((*res)->val, 3);
}

TEST(Find, can_find_leaf) {
  CNode* tree = create_tree_for_tests();
  CNode** res = (find(&tree, 4));
  ASSERT_EQ((*res)->val, 4);
}

TEST(Find, return_correct_adress_when_dont_find) {
  CNode* tree = create_tree_for_tests();
  CNode** res = (find(&tree, 8));
  CNode* null = 0;
  ASSERT_EQ(*res, null);
  *res = new CNode(8);
  CNode* new_search = *(find(&tree, 8));
  ASSERT_EQ(new_search->val, 8);
}

TEST(Find, dont_destruct_tree_when_can_find) {
  CNode* tree = create_tree_for_tests();
  CNode** res = (find(&tree, 1));

  ASSERT_EQ(tree->val, 5);
  ASSERT_EQ(tree->left->val, 3);
  ASSERT_EQ(tree->right->val, 7);
  ASSERT_EQ(tree->right->left->val, 6);
  ASSERT_EQ(tree->left->left->val, 1);
  ASSERT_EQ(tree->left->right->val, 4);
}

TEST(Find, dont_destruct_tree_when_cant_find) {
  CNode* tree = create_tree_for_tests();
  CNode** res = (find(&tree, 9));

  ASSERT_EQ(tree->val, 5);
  ASSERT_EQ(tree->left->val, 3);
  ASSERT_EQ(tree->right->val, 7);
  ASSERT_EQ(tree->right->left->val, 6);
  ASSERT_EQ(tree->left->left->val, 1);
  ASSERT_EQ(tree->left->right->val, 4);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
