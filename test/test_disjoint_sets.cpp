#include <gtest/gtest.h>
#include "disjoint_sets.h"

/*TEST(DISJOINT_SETS, can_create_set) {
  EXPECT_NO_THROW(Disjoint_Sets sets(4));
}*/

TEST(DISJOINT_SETS, can_work_when_try_union_same_sets) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  EXPECT_NO_THROW(sets.union_sets(1, 1));
}

TEST(DISJOINT_SETS, can_find_set) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  EXPECT_NO_THROW(sets.find_set(1));
}

TEST(DISJOINT_SETS, can_find_union_set) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  sets.union_sets(1, 2);
  sets.union_sets(2, 0);
  EXPECT_NO_THROW(sets.find_set(1));
}

TEST(DISJOINT_SETS, can_clear) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  sets.union_sets(1, 2);
  sets.union_sets(2, 0);
  EXPECT_NO_THROW(sets.clear());
}

TEST(DISJOINT_SETS, throw_when_try_make_set_with_too_large_index) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  EXPECT_ANY_THROW(sets.make_set(5));
}

TEST(DISJOINT_SETS, throw_when_try_make_set_with_negative_index) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  EXPECT_ANY_THROW(sets.make_set(-2));
}

TEST(DISJOINT_SETS, throw_when_try_union_sets_with_too_large_index) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  EXPECT_ANY_THROW(sets.union_sets(1, 5));
}

TEST(DISJOINT_SETS, throw_when_try_union_sets_with_negative_index) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  EXPECT_ANY_THROW(sets.union_sets(-2, 0));
}

TEST(DISJOINT_SETS, throw_when_try_union_dont_exict_sets) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  EXPECT_ANY_THROW(sets.union_sets(1, 2));
}

TEST(DISJOINT_SETS, make_set_correctly) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  EXPECT_EQ(sets.parent[1], 1);
}

TEST(DISJOINT_SETS, union_sets_correctly) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  sets.union_sets(2, 1);
  sets.union_sets(0, 1);
  EXPECT_EQ(sets.parent[0], 2);
}

TEST(DISJOINT_SETS, find_set_correctly) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  EXPECT_EQ(sets.find_set(0), 0);
}

TEST(DISJOINT_SETS, find_union_set_correctly) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  sets.union_sets(0, 1);
  sets.union_sets(1, 2);
  EXPECT_EQ(sets.find_set(2), 0);
}

TEST(DISJOINT_SETS, clear_correctly) {
  Disjoint_Sets sets(4);
  sets.make_set(1);
  sets.make_set(0);
  sets.make_set(2);
  sets.union_sets(1, 2);
  sets.union_sets(2, 0);
  sets.clear();
  EXPECT_EQ(sets.parent[0], -1);
  EXPECT_EQ(sets.parent[1], -1);
  EXPECT_EQ(sets.parent[2], -1);
}
