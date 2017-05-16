#include "gtest/gtest.h"
#include "d_heap.h"

/*TEST(PRIORITY_QUEUE_ON_HEAP, can_create_priority_queue_1) {
  ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue(4));
}*/

/*TEST(PRIORITY_QUEUE_ON_HEAP, can_create_priority_queue_2) {
  Data **data = new Data*[3];
  for (int i = 0; i < 3; i++) {
    data[i] = new Data;
    data[i]->priority = 1;
  }
  ASSERT_NO_THROW(PriorityQueue *q = new PriorityQueue(data, 3, 4));
}*/

TEST(PRIORITY_QUEUE_ON_HEAP, can_add_element_in_queue) {
  PriorityQueue *q = new PriorityQueue(4);
  Data *tmp = new Data;
  tmp->priority = 1;
  ASSERT_NO_THROW(q->add(&tmp));
  q->add(&tmp);
}

TEST(PRIORITY_QUEUE_ON_HEAP, add_in_queue_works_correctly) {
  PriorityQueue *q = new PriorityQueue(4);
  Data *tmp = new Data;
  tmp->priority = 4;
  q->add(&tmp);
  EXPECT_EQ(4, q->pop(0)->priority);
}

TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_add_element_into_full_queue) {
  Data **data = new Data*[MAXsize];
  for (int i = 0; i < MAXsize; i++) {
    data[i] = new Data;
    data[i]->priority = i;
  }
  PriorityQueue *q = new PriorityQueue(data, MAXsize, 4);
  Data* tmp = new Data();
  tmp->priority = 1;
  ASSERT_ANY_THROW(q->add(&tmp));
  q->pop(0);
}

TEST(PRIORITY_QUEUE_ON_HEAP, can_pop_element) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  ASSERT_NO_THROW(q->pop(1));
}

TEST(PRIORITY_QUEUE_ON_HEAP, pop_works_correctly) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  EXPECT_EQ(1, q->pop(0)->priority);
}

TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_pop_from_empty_queue) {
  PriorityQueue *q = new PriorityQueue(4);
  ASSERT_ANY_THROW(q->pop(0));
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  q->pop(0);
}

TEST(PRIORITY_QUEUE_ON_HEAP, can_pop_min_element) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  ASSERT_NO_THROW(q->pop_min());
}
TEST(PRIORITY_QUEUE_ON_HEAP, pop_min_works_correctly) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  Data* j = new Data();
  i->priority = 1;
  j->priority = 2;
  q->add(&i);
  q->add(&j);
  EXPECT_EQ(1, q->pop_min()->priority);
}

TEST(PRIORITY_QUEUE_ON_HEAP, throw_when_try_pop_min_from_empty_queue) {
  PriorityQueue *q = new PriorityQueue(4);
  ASSERT_ANY_THROW(q->pop_min());
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  q->pop_min();
}

TEST(PRIORITY_QUEUE_ON_HEAP, isFull_work_correctly) {
  Data **data = new Data*[MAXsize];
  for (int i = 0; i < MAXsize; i++) {
    data[i] = new Data;
    data[i]->priority = i;
  }
  PriorityQueue *q = new PriorityQueue(data, MAXsize, 2);
  ASSERT_TRUE(q->isFull());
  q->pop_min();
}

TEST(PRIORITY_QUEUE_ON_HEAP, isFull_work_correctly_when_queue_is_not_full) {
  PriorityQueue *q = new PriorityQueue(4);
  ASSERT_FALSE(q->isFull());
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
}

TEST(PRIORITY_QUEUE_ON_HEAP, isEmpty_work_correctly) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  q->pop(0);
  ASSERT_TRUE(q->isEmpty());
}

TEST(PRIORITY_QUEUE_ON_HEAP, isEmpty_work_correctly_when_queue_is_not_empty) {
  PriorityQueue *q = new PriorityQueue(4);
  Data* i = new Data();
  i->priority = 1;
  q->add(&i);
  ASSERT_FALSE(q->isEmpty());
}
