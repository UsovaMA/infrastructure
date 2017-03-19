#ifndef INCLUDE_CREATE_TREE_H_
#define INCLUDE_CREATE_TREE_H_

struct CNode {
  int val;
  CNode *left, *right;
  CNode() {}
  explicit CNode(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

CNode* create_tree_with_recursion(int *A, int left_end, int right_end);
CNode* create_tree(int *A, int size);
CNode** find(CNode**root, int v);
void PrintTree(CNode* root);
void print_tree(CNode* root, int level);

#endif  // INCLUDE_CREATE_TREE_H_
