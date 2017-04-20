#include "gtest/gtest.h"
#include "priority_queue.h"

/*TEST(PRIORITY_QUEUE_ON_HEAP, can_create_priority_queue_1) {
  ASSERT_NO_THROW(PriorityQueueHeap *q = new PriorityQueueHeap(2));
}*/

/*TEST(PRIORITY_QUEUE_ON_HEAP, can_create_priority_queue_2) {
  Data **data = new Data*[3];
  for (int i = 0; i < 3; i++) {
    data[i] = new Data;
    data[i]->priority = 1;
  }
  ASSERT_NO_THROW(PriorityQueueHeap *q = new PriorityQueueHeap(data, 3, 2));
}*/

TEST(PRIORITY_QUEUE_ON_HEAP, can_add_element_in_queue) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  Data *tmp = new Data;
  tmp->priority = 1;
  ASSERT_NO_THROW(q->add(&tmp));
}
TEST(PRIORITY_QUEUE_ON_HEAP, add_in_queue_works_correctly) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  Data *tmp = new Data;
  tmp->priority = 4;
  q->add(&tmp);
  EXPECT_EQ(4, q->pop(0)->priority);
}

/*TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_add_element_into_full_queue) {
  Data **data = new Data*[MAXsize];
  for (int i = 0; i < MAXsize; i++) {
    data[i] = new Data;
    data[i]->priority = i;
  }
  PriorityQueueHeap *q = new PriorityQueueHeap(data, MAXsize, 2);
  Data* tmp = new Data();
  tmp->priority = 1;
  ASSERT_ANY_THROW(q->add(&tmp));
}*/

TEST(PRIORITY_QUEUE_ON_HEAP, can_pop_element) {
  PriorityQueueHeap*q = new PriorityQueueHeap(2);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  ASSERT_NO_THROW(q->pop(1));
}

TEST(PRIORITY_QUEUE_ON_HEAP, pop_works_correctly) {
  PriorityQueueHeap*q = new PriorityQueueHeap(2);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  EXPECT_EQ(1, q->pop(0)->priority);
}

/*TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_pop_from_empty_queue) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  ASSERT_ANY_THROW(q->pop(0));
}*/

TEST(PRIORITY_QUEUE_ON_HEAP, can_pop_min_element) {
  PriorityQueueHeap*q = new PriorityQueueHeap(2);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  ASSERT_NO_THROW(q->pop_min());
}
TEST(PRIORITY_QUEUE_ON_HEAP, pop_min_works_correctly) {
  PriorityQueueHeap*q = new PriorityQueueHeap(2);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  EXPECT_EQ(2, q->pop_min()->priority);
}

/*TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_pop_min_from_empty_queue) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  ASSERT_ANY_THROW(q->pop_min());
}*/

/*TEST(PRIORITY_QUEUE_ON_HEAP, isFull_work_correctly) {
  Data **data = new Data*[MAXsize];
  for (int i = 0; i < MAXsize; i++) {
    data[i] = new Data;
    data[i]->priority = i;
  }
  PriorityQueueHeap *q = new PriorityQueueHeap(data, MAXsize, 2);
  ASSERT_TRUE(q->isFull());
}*/

/*TEST(PRIORITY_QUEUE_ON_HEAP, isFull_work_correctly_when_queue_is_not_full) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  ASSERT_FALSE(q->isFull());
}*/

TEST(PRIORITY_QUEUE_ON_HEAP, isEmpty_work_correctly) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  q->pop(0);
  ASSERT_TRUE(q->isEmpty());
}

TEST(PRIORITY_QUEUE_ON_HEAP, isEmpty_work_correctly_when_queue_is_not_empty) {
  PriorityQueueHeap *q = new PriorityQueueHeap(2);
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  ASSERT_FALSE(q->isEmpty());
}
