#include <gtest/gtest.h>
#include "create_tree.h"

TEST(Create_Tree, can_create_empty_tree) {
  EXPECT_NO_THROW(create_tree(NULL, 0));
}

TEST(Create_Tree, can_create_tree_ex_1_1) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  EXPECT_NO_THROW(create_tree(A, size));
}

TEST(Create_Tree, can_create_tree_ex_1_2) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = create_tree(A, size);

  CNode* true_tree = new CNode(2);
  true_tree->left = new CNode(1);
  true_tree->right = new CNode(3);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
}

TEST(Create_Tree, can_create_tree_ex_2_1) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 5 };

  EXPECT_NO_THROW(create_tree(A, size));
}

TEST(Create_Tree, can_create_tree_ex_2_2) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 5 };

  CNode* tree = create_tree(A, size);

  CNode* true_tree = new CNode(3);
  true_tree->left = new CNode(1);
  true_tree->right = new CNode(4);
  true_tree->left->right = new CNode(2);
  true_tree->right->right = new CNode(5);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
  ASSERT_EQ(tree->left->right->val, true_tree->left->right->val);
  ASSERT_EQ(tree->right->right->val, true_tree->right->right->val);
}

TEST(Create_Tree, create_tree_can_work_with_function) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = create_tree(A, size);

  EXPECT_EQ(*(find(&tree, 2)), tree);
  EXPECT_EQ(*(find(&tree, 1)), tree->left);
  EXPECT_EQ(*(find(&tree, 3)), tree->right);
}

TEST(Create_Tree_With_Recursion, can_create_empty_tree) {
  EXPECT_NO_THROW(create_tree_with_recursion(NULL, 0, -1));
}

TEST(Create_Tree_With_Recursion, can_create_tree_ex_1_1) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  EXPECT_NO_THROW(create_tree_with_recursion(A, 0, size - 1));
}

TEST(Create_Tree_With_Recursion, can_create_tree_ex_1_2) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = create_tree_with_recursion(A, 0, size - 1);

  CNode* true_tree = new CNode(2);
  true_tree->left = new CNode(1);
  true_tree->right = new CNode(3);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
}

TEST(Create_Tree_With_Recursion, can_create_tree_ex_2_1) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 5 };

  EXPECT_NO_THROW(create_tree_with_recursion(A, 0, size - 1));
}

TEST(Create_Tree_With_Recursion, can_create_tree_ex_2_2) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 5 };

  CNode* tree = create_tree_with_recursion(A, 0, size - 1);

  CNode* true_tree = new CNode(3);
  true_tree->left = new CNode(1);
  true_tree->right = new CNode(4);
  true_tree->left->right = new CNode(2);
  true_tree->right->right = new CNode(5);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
  ASSERT_EQ(tree->left->right->val, true_tree->left->right->val);
  ASSERT_EQ(tree->right->right->val, true_tree->right->right->val);
}

TEST(Create_Tree_With_Recursion, create_tree_can_work_with_function) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = nullptr;
  tree = create_tree_with_recursion(A, 0, size - 1);

  EXPECT_EQ(*(find(&tree, 2)), tree);
  EXPECT_EQ(*(find(&tree, 1)), tree->left);
  EXPECT_EQ(*(find(&tree, 3)), tree->right);
}

TEST(Create_Tree_2, can_create_empty_tree) {
  EXPECT_NO_THROW(CreateTree(NULL, 0));
}

TEST(Create_Tree_2, can_create_tree_ex_1_1) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  EXPECT_NO_THROW(CreateTree(A, size));
}

TEST(Create_Tree_2, can_create_tree_ex_1_2) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = CreateTree(A, size);

  CNode* true_tree = new CNode(2);
  true_tree->left = new CNode(1);
  true_tree->right = new CNode(3);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
}

TEST(Create_Tree_2, can_create_tree_ex_2_1) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 5 };

  EXPECT_NO_THROW(CreateTree(A, size));
}

TEST(Create_Tree_2, can_create_tree_ex_2_2) {
  const int size = 5;
  int A[size] = { 1, 2, 3, 4, 6 };

  CNode* tree = CreateTree(A, size);

  CNode* true_tree = new CNode(3);
  true_tree->left = new CNode(2);
  true_tree->right = new CNode(6);
  true_tree->left->left = new CNode(1);
  true_tree->right->left = new CNode(4);

  ASSERT_EQ(tree->val, true_tree->val);
  ASSERT_EQ(tree->left->val, true_tree->left->val);
  ASSERT_EQ(tree->right->val, true_tree->right->val);
  ASSERT_EQ(tree->left->left->val, true_tree->left->left->val);
  ASSERT_EQ(tree->right->left->val, true_tree->right->left->val);
}

TEST(Create_Tree_2, create_tree_can_work_with_function) {
  const int size = 3;
  int A[size] = { 1, 2, 3 };

  CNode* tree = CreateTree(A, size);

  EXPECT_EQ(*(find(&tree, 2)), tree);
  EXPECT_EQ(*(find(&tree, 1)), tree->left);
  EXPECT_EQ(*(find(&tree, 3)), tree->right);
}
