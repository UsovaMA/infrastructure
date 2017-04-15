#include <iostream>
#include <queue>
#include <tuple>
#include "create_tree.h"

CNode* create_tree_with_recursion(int *A, int left_end, int right_end) {
  CNode* tree;
  CNode* tmp;
  int middle;
  if (left_end > right_end) {
    tree = nullptr;
  } else {
    middle = (left_end + right_end) / 2;
    tmp = new CNode;
    tmp->val = A[middle];
    tmp->left = create_tree_with_recursion(A, left_end, middle - 1);
    tmp->right = create_tree_with_recursion(A, middle + 1, right_end);
    tree = tmp;
  }
  return tree;
}

CNode* create_tree(int *A, int size) {
  CNode* tree = nullptr;
  int left_end = 0, right_end = size - 1, middle;
  std::queue<int> q;
  q.push(left_end);
  q.push(right_end);
  while (!q.empty()) {
    left_end = q.front();
    q.pop();
    right_end = q.front();
    q.pop();
    if (left_end > right_end) {
      continue;
    }
    middle = (left_end + right_end) / 2;
    CNode** tmp = find(&tree, A[middle]);
    *tmp = new CNode(A[middle]);
    q.push(left_end);
    q.push(middle - 1);
    q.push(middle + 1);
    q.push(right_end);
  }
  return tree;
}

CNode* CreateTree(int* A, int size) {
  std::queue<std::tuple<CNode**, int, int>> q;
  CNode* tree;
  int middle;
  if (A == nullptr)
    return nullptr;
  q.push(std::make_tuple(&tree, 0, size));

  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    middle = (std::get<1>(node) + std::get<2>(node)) / 2;
    if (std::get<1>(node) < std::get<2>(node)) {
      *(std::get<0>(node)) = new CNode(A[middle]);
      q.push(std::make_tuple
      (&(*(std::get<0>(node)))->left, (std::get<1>(node)), middle));
      q.push(std::make_tuple
      (&(*(std::get<0>(node)))->right, middle+1, std::get<2>(node)));
    }
  }
  return tree;
}

CNode** find(CNode** root, int v) {
  CNode **tree = root;
  while (*tree) {
    if ((*tree)->val == v) {
      return tree;
    } else {
      if ((*tree)->val < v) {
        tree = &(*tree)->right;
      } else {
        tree = &(*tree)->left;
      }
    }
  }
  return tree;
}

void PrintTree(CNode* root) {
  std::queue <CNode*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      CNode* e = q.front();
      q.pop();
      if (e == nullptr)
        continue;
      std::cout << e->val << " ";
      q.push(e->left);
      q.push(e->right);
    }
    std::cout << std::endl;
  }
}

void print_tree(CNode* root, int level) {
  if (root) {
    print_tree(root->right, level + 1);
    for (int i = 0; i< level; i++) std::cout << "    ";
    std::cout << root->val << std::endl;
    print_tree(root->left, level + 1);
  }
}
