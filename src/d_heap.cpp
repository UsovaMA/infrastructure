#include "d_heap.h"

/* Конструкторы */
D_Heap::D_Heap(int d) {
  if (d <= 0)
    throw std::logic_error("Input error: invalid d.\n");
  this->d = d;
  size = -1;
  key = new Data*[MAXsize];
}

D_Heap::D_Heap(const D_Heap &heap) {
  this->d = heap.d;
  key = new Data*[MAXsize];
  for (int i = 0; i <= heap.size; i++)
    key[i] = heap.key[i];
  this->size = heap.size;
}

/* Деструктор */
D_Heap::~D_Heap() {
  delete[] key;
}

/* Формулы вычисления потомка и родителя */
int D_Heap::Child(int i) {
  return d * i + 1;
}
int D_Heap::Parent(int i) {
  return (i - 1) / d;
}

int D_Heap::isFull() {
  return size >= MAXsize - 1;
}

int D_Heap::isEmpty() {
  return size == -1;
}

/* Вставка элемента в кучу */
void D_Heap::insert(Data **i) {
  if (isFull())
    throw std::logic_error("Heap is FULL.\n");
  size++;
  key[size] = *i;
  surfacing(size);
}

/* Вставка группы элементов в кучу */
void D_Heap::insert_group(Data **keys, int num) {
  if (size + num >= MAXsize)
    throw std::logic_error("Input error: too large set.\n");
  for (int i = 0; i < num; i++)
    key[i + size + 1] = keys[i];
  size += num;
  hilling();
}

/* Стирание */
Data* D_Heap::erase() {
  if (isEmpty())
    throw std::logic_error("Heap is empty.\n");
  Data* keys = key[size];
  size--;
  return keys;
}

Data* D_Heap::erase(int i) {
  if (isEmpty())
    throw std::logic_error("Heap is empty.\n");
  if ((i < 0) || (i > size))
    throw std::logic_error("Input error: invalid index.\n");
  Data* keys = key[i];
  if (i == size) {
    size--;
    return keys;
  }
  transposition(i, size);
  size--;
  immersion(i);
  return keys;
}

/* Обмен переданных значений */
void D_Heap::transposition(int i, int j) {
  if ((i < 0) || (j < 0) || (i > size) || (j > size))
    throw std::logic_error("Input error: invalid indexes.\n");
  Data* tmp = key[i];
  key[i] = key[j];
  key[j] = tmp;
}

/* Всплытие */
void D_Heap::surfacing(int i) {
  if ((i < 0) || (i > size))
    throw std::logic_error("Input error: invalid index.\n");
  int p = Parent(i);
  while (i > 0) {
    if (key[p]->priority < key[i]->priority)
      break;
    transposition(p, i);
    i = p;
    p = Parent(i);
  }
}

/* Погружение */
void D_Heap::immersion(int i) {
  if ((i < 0) || (i > size))
    throw std::logic_error("Input error: invalid index.\n");
  int c = min_Child(i);
  while ((c != -1) && (key[c]->priority < key[i]->priority)) {
    transposition(i, c);
    i = c;
    c = min_Child(i);
  }
}

/* Окучивание */
void D_Heap::hilling() {
  for (int i = size; i >= 0; i--)
    immersion(i);
}

/* Поиск минимального потомка */
int D_Heap::min_Child(int i) {
  int ch = Child(i);
  if (ch > size)
    return -1;
  int l;
  if (i * d + d > size) {
    l = size;
  } else {
    l = i * d + d;
  }
  int c;
  Data* minKey = key[ch];
  c = ch;
  for (int k = ch + 1; k <= l; k++) {
    if (minKey->priority > key[k]->priority) {
      minKey = key[k];
      c = k;
    }
  }
  return c;
}
