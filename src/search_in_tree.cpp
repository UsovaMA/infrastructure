#include <iostream>
#include <queue>
#include "search_in_tree.h"

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

void print_tree(CNode* root, int level) {
  if (root) {
    print_tree(root->right, level + 1);
    for (int i = 0; i< level; i++) std::cout << "    ";
    std::cout << root->val << std::endl;
    print_tree(root->left, level + 1);
  }
}

void print_tree_with_adress(CNode* root, int level) {
  if (root) {
    print_tree_with_adress(root->right, level + 1);
    for (int i = 0; i< level; i++) std::cout << "       ";
    std::cout << root->val << std::endl;
    for (int i = 0; i< level-1; i++) std::cout << "       ";
    std::cout << "   ";
    std::cout << root->left << std::endl;
    for (int i = 0; i< level-1; i++) std::cout << "       ";
    std::cout << "   ";
    std::cout << root->right << std::endl;
    print_tree_with_adress(root->left, level + 1);
  }
}

CNode* create_tree_for_tests() {
  CNode* tree = new CNode(5);
  tree->left = new CNode(3);
  tree->right = new CNode(7);
  (tree->right)->left = new CNode(6);
  (tree->left)->left = new CNode(1);
  (tree->left)->right = new CNode(4);
  return tree;
}
