#include "priority_queue.h"
#include "RBtree.h"

/*----------------------------------------------------*/
/*           Приоритетная очередь на 2-куче           */
/*----------------------------------------------------*/

/* Конструкторы */
PriorityQueueHeap::PriorityQueueHeap(int d) {
  heap = new D_Heap(d = 2);
}

PriorityQueueHeap::PriorityQueueHeap(Data **keys, int num, int d) {
  heap = new D_Heap(d = 2);
  heap->insert_group(keys, num);
}

/* Деструктор */
PriorityQueueHeap ::~PriorityQueueHeap() {
  delete heap;
}

int PriorityQueueHeap::isFull() {
  return heap->isFull();
}

int PriorityQueueHeap::isEmpty() {
  return heap->isEmpty();
}

/* Добавление ключа в очередь */
void PriorityQueueHeap::add(Data **key) {
  heap->insert(key);
}

/* Удаление */
Data* PriorityQueueHeap::pop(int i) {
  return heap->erase(i);
}

/* Удаление минимального */
Data* PriorityQueueHeap::pop_min() {
  return heap->erase();
}

/* Обновление очереди */
void PriorityQueueHeap::update() {
  heap->hilling();
}
