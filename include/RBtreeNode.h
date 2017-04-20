#ifndef INCLUDE_RBTREENODE_H_
#define INCLUDE_RBTREENODE_H_

#define COLOR_RED 1
#define COLOR_BLACK 0
#define NullNode &EmptyNode

template <class T>
struct RBtreeNode {
  T value;
  int color;
  RBtreeNode *left;
  RBtreeNode *right;
  RBtreeNode *parent;
};

extern RBtreeNode<int> EmptyNode;

#endif  // INCLUDE_RBTREENODE_H_
