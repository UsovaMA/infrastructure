#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_

#include "RBtreeNode.h"
#include <stdio.h>

template <class T>
class RBTree {
  RBtreeNode<T>* root;

  void left_rotate(RBtreeNode<T> *node);
  void right_rotate(RBtreeNode<T> *node);
  void fixup_after_insert(RBtreeNode<T> *node);
  void fixup_after_delete(RBtreeNode<T> *node);
 public:
  RBTree();
  explicit RBTree(T _val);
  ~RBTree(void);
  RBtreeNode<T>* get_root();

  void RB_insert(T _val);
  void RB_delete(T _val);
  RBtreeNode<T>* RB_find(T _val);
  RBtreeNode<T>* get_min();
};

/* Конструкторы */
template <class T>
RBTree<T>::RBTree() {
  root = reinterpret_cast<RBtreeNode<T>*>(NullNode);
}

template <class T>
RBTree<T>::RBTree(T _val) {
  root = new RBtreeNode<T>;
  root->value = _val;
  root->color = COLOR_BLACK;
  root->left = root->right = reinterpret_cast<RBtreeNode<T>*>(NullNode);
  root->parent = 0;
}

/* Деструктор */
template <class T>
RBTree<T>::~RBTree(void) {
  while (root != reinterpret_cast<RBtreeNode<T>*>(NullNode))
    RB_delete(root->value);
}

template <class T>
RBtreeNode<T>* RBTree<T>::get_root() {
  return root;
}

/* Левый поворот */
template <class T>
void RBTree<T>::left_rotate(RBtreeNode<T> *node) {
  RBtreeNode<T> *right = node->right;
  node->right = right->left;

  if (right->left != reinterpret_cast<RBtreeNode<T>*>(NullNode))
    right->left->parent = node;
  right->parent = node->parent;

  if (node->parent != 0) {
    if (node == node->parent->left) {
      node->parent->left = right;
    } else {
      node->parent->right = right;
    }
  } else {
    root = right;
  }
  right->left = node;
  node->parent = right;
}

/* Правый поворот */
template <class T>
void RBTree<T>::right_rotate(RBtreeNode<T> *node) {
  RBtreeNode<T> *left = node->left;
  node->left = left->right;

  if (left->right != reinterpret_cast<RBtreeNode<T>*>(NullNode))
    left->right->parent = node;
  left->parent = node->parent;

  if (node->parent != 0) {
    if (node == node->parent->left) {
      node->parent->left = left;
    } else {
      node->parent->right = left;
    }
  } else {
    root = left;
  }
  left->right = node;
  node->parent = left;
}

/* Восстановление свойств после добавления */
template <class T>
void RBTree<T>::fixup_after_insert(RBtreeNode<T> *node) {
  while ((node != root) && (node->parent->color == COLOR_RED)) {
    // узел в левом поддереве grandfather
    if (node->parent == node->parent->parent->left) {
      RBtreeNode<T> *uncle = node->parent->parent->right;
      if (uncle->color == COLOR_RED) {
        // случай 1 - uncle RED
        node->parent->color = COLOR_BLACK;
        uncle->color = COLOR_BLACK;
        node->parent->parent->color = COLOR_RED;
        node = node->parent->parent;
      } else {
        // случаи 2 и 3 - uncle BLACK
        if (node == node->parent->right) {
          // сведение случая 2 к случаю 3
          node = node->parent;
          left_rotate(node);
        }
        // случай 3
        node->parent->color = COLOR_BLACK;
        node->parent->parent->color = COLOR_RED;
        right_rotate(node->parent->parent);
      }
    } else {
      // узел в правом поддереве grandfather
      RBtreeNode<T> *y = node->parent->parent->left;
      if (y->color == COLOR_RED) {
        // случай 4 - uncle RED
        node->parent->color = COLOR_BLACK;
        y->color = COLOR_BLACK;
        node->parent->parent->color = COLOR_RED;
        node = node->parent->parent;
      } else {
        // случаи 5 и 6 - uncle BLACK
        if (node == node->parent->left) {
          // сведение случая 5 к случаю 6
          node = node->parent;
          right_rotate(node);
        }
        // случай 6
        node->parent->color = COLOR_BLACK;
        node->parent->parent->color = COLOR_RED;
        left_rotate(node->parent->parent);
      }
    }
  }
  root->color = COLOR_BLACK;
}

/* Добавление узла */
template <class T>
void RBTree<T>::RB_insert(T _val) {
  RBtreeNode<T> *node = root, *parent = 0, *newnode = 0;

  // поиск листа для нового элемента
  while (node != reinterpret_cast<RBtreeNode<T>*>(NullNode)) {
    if (node->value == _val)
      throw std::logic_error("Input error: such value alreade exist.\n");
    parent = node;
    if (_val < node->value) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  newnode = new RBtreeNode<T>;
  newnode->value = _val;
  newnode->color = COLOR_RED;
  newnode->left = reinterpret_cast<RBtreeNode<T>*>(NullNode);
  newnode->right = reinterpret_cast<RBtreeNode<T>*>(NullNode);
  newnode->parent = parent;

  if (parent == 0) {
    root = newnode;
  } else {
    if (_val < parent->value) {
      parent->left = newnode;
    } else {
      parent->right = newnode;
    }
  }
  fixup_after_insert(newnode);
}

/* Восстановление свойств после удаления */
template <class T>
void RBTree<T>::fixup_after_delete(RBtreeNode<T> *node) {
  while ((node != root) && (node->color == COLOR_BLACK)) {
    // узел в левом поддереве grandfather
    if (node == node->parent->left) {
      RBtreeNode<T> *uncle = node->parent->right;
      if (uncle->color == COLOR_RED) {
        // случай 1 - uncle RED
        uncle->color = COLOR_BLACK;
        node->parent->color = COLOR_RED;
        left_rotate(node->parent);
        uncle = node->parent->right;
      }
      if ((uncle->left->color == COLOR_BLACK) &&
        (uncle->right->color == COLOR_BLACK)) {
        // случаи 2 и 3 - uncle BLACK
        uncle->color = COLOR_RED;
        node = node->parent;
      } else {
        // случай 3
        if (uncle->right->color == COLOR_BLACK) {
          uncle->left->color = COLOR_BLACK;
          uncle->color = COLOR_RED;
          right_rotate(uncle);
          uncle = node->parent->right;
        }
        // случай 4
        uncle->color = node->parent->color;
        node->parent->color = COLOR_BLACK;
        uncle->right->color = COLOR_BLACK;
        left_rotate(node->parent);
        node = root;
      }
    } else {
      // узел в левом поддереве grandfather
      RBtreeNode<T> *uncle = node->parent->left;
      if (uncle->color == COLOR_RED) {
        uncle->color = COLOR_BLACK;
        node->parent->color = COLOR_RED;
        right_rotate(node->parent);
        uncle = node->parent->left;
      }
      if ((uncle->right->color == COLOR_BLACK) &&
        (uncle->left->color == COLOR_BLACK)) {
        // случаи 6 и 7 - uncle BLACK
        uncle->color = COLOR_RED;
        node = node->parent;
      } else {
        // случай 7
        if (uncle->left->color == COLOR_BLACK) {
          uncle->right->color = COLOR_BLACK;
          uncle->color = COLOR_RED;
          left_rotate(uncle);
          uncle = node->parent->left;
        }
        // случай 8
        uncle->color = node->parent->color;
        node->parent->color = COLOR_BLACK;
        uncle->left->color = COLOR_BLACK;
        right_rotate(node->parent);
        node = root;
      }
    }
  }
  node->color = COLOR_BLACK;
}

/* Удаление узла */
template <class T>
void RBTree<T>::RB_delete(T _val) {
  RBtreeNode<T> *node, *parent, *_node;

  _node = root;
  while (_node != reinterpret_cast<RBtreeNode<T>*>(NullNode)) {
    if (_node->value == _val) {
      break;
    } else {
      if (_val < _node->value) {
        _node = _node->left;
      } else {
        _node = _node->right;
      }
    }
  }

  if (_node == reinterpret_cast<RBtreeNode<T>*>(NullNode))
    throw std::logic_error("Input error: value doesn't exist.\n");
  if ((_node->left == reinterpret_cast<RBtreeNode<T>*>(NullNode)) ||
    (_node->right == reinterpret_cast<RBtreeNode<T>*>(NullNode))) {
    parent = _node;
  } else {
    parent = _node->right;
    while (parent->left != reinterpret_cast<RBtreeNode<T>*>(NullNode))
      parent = parent->left;
  }
  if (parent->left != reinterpret_cast<RBtreeNode<T>*>(NullNode)) {
    node = parent->left;
  } else {
    node = parent->right;
  }
  node->parent = parent->parent;
  if (parent->parent != 0) {
    if (parent == parent->parent->left) {
      parent->parent->left = node;
    } else {
      parent->parent->right = node;
    }
  } else {
    root = node;
  }
  if (parent != _node)
    _node->value = parent->value;
  if (parent->color == COLOR_BLACK)
    fixup_after_delete(node);
  delete parent;
}

/* Поиск по значению */
template <class T>
RBtreeNode<T>* RBTree<T>::RB_find(T _val) {
  RBtreeNode<T> *cur = root;
  while (cur != 0) {
    if (_val == cur->value) {
      return cur;
    } else {
      if (_val < cur->value) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
  }
  throw std::logic_error("Don't found.\n");
}

template<class T>
RBtreeNode<T>* RBTree<T>::get_min() {
  RBtreeNode<T>* node = root;
  while (node->left != reinterpret_cast<RBtreeNode<T>*>(NullNode)) {
    node = node->left;
  }
  return node;
}

#endif  // INCLUDE_RBTREE_H_
