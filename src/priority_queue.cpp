#include "priority_queue.h"
#include "RBtree.h"

/*----------------------------------------------------*/
/*           ������������ ������� �� 2-����           */
/*----------------------------------------------------*/

/* ������������ */
PriorityQueueHeap::PriorityQueueHeap(int d) {
  heap = new D_Heap(d = 2);
}

PriorityQueueHeap::PriorityQueueHeap(Data **keys, int num, int d) {
  heap = new D_Heap(d = 2);
  heap->insert_group(keys, num);
}

/* ���������� */
PriorityQueueHeap ::~PriorityQueueHeap() {
  delete heap;
}

int PriorityQueueHeap::isFull() {
  return heap->isFull();
}

int PriorityQueueHeap::isEmpty() {
  return heap->isEmpty();
}

/* ���������� ����� � ������� */
void PriorityQueueHeap::add(Data **key) {
  heap->insert(key);
}

/* �������� */
Data* PriorityQueueHeap::pop(int i) {
  return heap->erase(i);
}

/* �������� ������������ */
Data* PriorityQueueHeap::pop_min() {
  return heap->erase();
}

/* ���������� ������� */
void PriorityQueueHeap::update() {
  heap->hilling();
}
