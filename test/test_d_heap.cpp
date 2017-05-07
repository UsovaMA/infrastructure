#include <gtest/gtest.h>
#include "d_heap.h"

/*TEST(D_HEAP, can_create_d_heap) {
  ASSERT_NO_THROW(D_Heap *heap = new D_Heap(4));
}*/

TEST(D_HEAP, can_insert_new_key) {
  D_Heap *heap = new D_Heap(4);
  Data* key = new Data();
  key->priority = 4;
  ASSERT_NO_THROW(heap->insert(&key));
}

TEST(D_HEAP, can_insert_group_in_heap) {
  Data **g_key = new Data*[4];
  for (int i = 0; i < 4; i++) {
    g_key[i] = new Data;
    g_key[i]->priority = 4;
  }
  D_Heap *heap = new D_Heap(2);
  ASSERT_NO_THROW(heap->insert_group(g_key, 4));
}

TEST(D_HEAP, can_erase_element) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_NO_THROW(heap->erase());
}

TEST(D_HEAP, can_make_transposition_of_elements) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_NO_THROW(heap->transposition(0, 1));
}

TEST(D_HEAP, can_surfacing) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_NO_THROW(heap->surfacing(0));
}

TEST(D_HEAP, can_immersion) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  Data* k = new Data();
  i->priority = 1;
  j->priority = 2;
  j->priority = 3;
  heap->insert(&i);
  heap->insert(&j);
  heap->insert(&k);
  ASSERT_NO_THROW(heap->immersion(1));
}

TEST(D_HEAP, correct_work_of_erase) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  j->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  Data *k = heap->erase(1);
  EXPECT_EQ(2, k->priority);
}

TEST(D_HEAP, correct_work_of_transposition) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  heap->transposition(0, 1);
  Data* k = heap->erase(1);
  Data* p = heap->erase(0);
  EXPECT_EQ(k->priority, 1);
  EXPECT_EQ(p->priority, 2);
}

TEST(D_HEAP, immersion_works_correctly) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  Data* k = new Data();
  i->priority = 1;
  j->priority = 2;
  j->priority = 3;
  heap->insert(&i);
  heap->insert(&j);
  heap->insert(&k);
  heap->immersion(1);
  EXPECT_EQ(1, heap->erase(2)->priority);
}

TEST(D_HEAP, can_find_min_child_1) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  Data* k = new Data();
  i->priority = 1;
  j->priority = 2;
  j->priority = 3;
  heap->insert(&i);
  heap->insert(&j);
  heap->insert(&k);
  EXPECT_EQ(heap->min_Child(0), 2);
}

/*TEST(D_HEAP, throw_when_try_create_heap_with_negative_d) {
  ASSERT_ANY_THROW(D_Heap *heap = new D_Heap(-5));
}*/

TEST(D_HEAP, throw_when_try_insert_key_into_full_heap) {
  D_Heap *heap = new D_Heap(4);
  for (int i = 0; i < MAXsize; i++) {
    Data* key = new Data();
    key->priority = 4;
    heap->insert(&key);
  }
  Data *key = new Data();
  key->priority = 4;
  ASSERT_ANY_THROW(heap->insert(&key));
}

TEST(D_HEAP, throw_when_try_insert_group_in_full_heap) {
  D_Heap *heap = new D_Heap(4);
  for (int i = 0; i < MAXsize; i++) {
    Data *key = new Data();
    key->priority = 4;
    heap->insert(&key);
  }
  Data **g_key = new Data*[4];
  for (int i = 0; i < 4; i++) {
    g_key[i] = new Data;
    g_key[i]->priority = 4;
  }
  ASSERT_ANY_THROW(heap->insert_group(g_key, 4));
}

TEST(D_HEAP, throw_when_try_erase_element_from_empty_heap) {
  D_Heap *heap = new D_Heap(4);
  ASSERT_ANY_THROW(heap->erase());
  Data* i = new Data();
  i->priority = 1;
  heap->insert(&i);
}

TEST(D_HEAP, throw_when_try_erase_negative_missing_element) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->erase(-1));
}

TEST(D_HEAP, throw_when_try_erase_missing_element) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->erase(3));
}

TEST(D_HEAP, throw_when_try_make_transposition_elements_with_negative_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->transposition(-1, 0));
}
TEST(D_HEAP, throw_when_try_make_transposition_elements_with_missing_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->transposition(0, 3));
}

TEST(D_HEAP, throw_when_try_surfacing_with_negative_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->surfacing(-1));
}

TEST(D_HEAP, throw_when_try_surfacing_with_missing_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  heap->insert(&i);
  heap->insert(&j);
  ASSERT_ANY_THROW(heap->surfacing(3));
}

TEST(D_HEAP, throw_when_try_immersion_with_missing_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  Data* k = new Data();
  i->priority = 1;
  j->priority = 2;
  j->priority = 3;
  heap->insert(&i);
  heap->insert(&j);
  heap->insert(&k);
  ASSERT_ANY_THROW(heap->immersion(3));
}

TEST(D_HEAP, throw_when_try_immersion_with_negative_index) {
  D_Heap *heap = new D_Heap(4);
  Data* i = new Data();
  Data* j = new Data();
  Data* k = new Data();
  i->priority = 1;
  j->priority = 2;
  j->priority = 3;
  heap->insert(&i);
  heap->insert(&j);
  heap->insert(&k);
  ASSERT_ANY_THROW(heap->immersion(-1));
}

TEST(D_HEAP, isFull_work_correctly) {
  D_Heap *heap = new D_Heap(4);
  for (int i = 0; i < MAXsize; i++) {
    Data* j = new Data();
    j->priority = 1;
    heap->insert(&j);
  }
  ASSERT_TRUE(heap->isFull());
}

TEST(D_HEAP, isFull_works_correctly_when_heap_not_full) {
  D_Heap *heap = new D_Heap(4);
  Data* j = new Data();
  j->priority = 1;
  heap->insert(&j);
  ASSERT_FALSE(heap->isFull());
}

TEST(D_HEAP, isEmpty_work_correctly) {
  D_Heap *heap = new D_Heap(4);
  Data* j = new Data();
  j->priority = 1;
  heap->insert(&j);
  heap->erase(0);
  ASSERT_TRUE(heap->isEmpty());
}

TEST(D_HEAP, isEmpty_works_correctly_when_heap_not_empty) {
  D_Heap *heap = new D_Heap(4);
  Data* j = new Data();
  j->priority = 1;
  heap->insert(&j);
  ASSERT_FALSE(heap->isEmpty());
}
