#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_
#include "d_heap.h"
#include "RBtree.h"

/*----------------------------------------------------*/
/*           ������������ ������� �� 2-����           */
/*----------------------------------------------------*/

class PriorityQueueHeap {
 protected:
  D_Heap *heap;
 public:
  explicit PriorityQueueHeap(int d);
  PriorityQueueHeap(Data **keys, int num, int d);
  ~PriorityQueueHeap();
  int isFull();
  int isEmpty();

  void add(Data **key);
  Data* pop(int i);
  Data* pop_min();
  void update();
};

/*----------------------------------------------------*/
/*   ������������ ������� �� ������-������ ��������   */
/*----------------------------------------------------*/

template <class T>
class PriorityQueueRBtree {
  RBTree<T> tree;

 public:
  int isEmpty();

  void add(T _val);
  void pop(T _val);
  RBtreeNode<T>* find(T _val);
  RBtreeNode<T>* min();
};

/*----------------------------------------------------*/
/*   ������������ ������� �� ������-������ ��������   */
/*----------------------------------------------------*/

/* ����� */
template <class T>
RBtreeNode<T>* PriorityQueueRBtree<T>::find(T _val) {
  return tree.RB_find(_val);
}

/* ����������� */
template <class T>
RBtreeNode<T>* PriorityQueueRBtree<T>::min() {
  return tree.get_min();
}

/* ������� */
template <class T>
void PriorityQueueRBtree<T>::add(T _val) {
  tree.RB_insert(_val);
}

/* �������� */
template <class T>
void PriorityQueueRBtree<T>::pop(T _val) {
  tree.RB_delete(_val);
}

template <class T>
int PriorityQueueRBtree<T>::isEmpty() {
  return (tree.get_root() == reinterpret_cast<RBtreeNode<T>*>(NullNode));
}

#endif  // INCLUDE_PRIORITY_QUEUE_H_
