#ifndef INCLUDE_SEARCH_IN_TREE_H_
#define INCLUDE_SEARCH_IN_TREE_H_

struct CNode {
  int val;
  CNode* left, *right;
  explicit CNode(int v) { val = v; left = 0; right = 0; }
};

CNode** find(CNode** root, int v);
void print_tree(CNode* root, int level);
void print_tree_with_adress(CNode* root, int level);
CNode* create_tree_for_tests();
void PrintTree(CNode** root);

#endif  // INCLUDE_SEARCH_IN_TREE_H_
