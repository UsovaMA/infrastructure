#include <gtest/gtest.h>
#include "massive.h"

TEST(MadeMassive, throw_when_work_with_empty_massive) {
  const int N = 0;
  int* a = nullptr;

  EXPECT_ANY_THROW(int* res = made_massive(a, 0));
}

TEST(MadeMassive, can_work_with_massive_of_one_element) {
  const int N = 1;
  int a[1] = { 5 };
  int exp[1] = { 1 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}

TEST(MadeMassive, can_work_with_massive_with_null_element) {
  const int N = 6;
  int a[6] = { 1, 2, 0, 4, 1, 1 };
  int exp[6] = { 0, 0, 8, 0, 0, 0 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}

TEST(MadeMassive, can_work_with_massive_with_null_elements) {
  const int N = 6;
  int a[6] = { 1, 2, 0, 4, 0, 1 };
  int exp[6] = { 0, 0, 0, 0, 0, 0 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}

TEST(MadeMassive, can_work_with_simple_massive_1) {
  const int N = 6;
  int a[6] = { 1, 2, 3, 4, 1, 5 };
  int exp[6] = { 120, 60, 40, 30, 120, 24 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}

TEST(MadeMassive, can_work_with_simple_massive_2) {
  const int N = 6;
  int a[6] = { 1, 1, 1, 1, 1, 1 };
  int exp[6] = { 1, 1, 1, 1, 1, 1 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}

TEST(MadeMassive, can_work_with_simple_massive_3) {
  const int N = 6;
  int a[6] = { 3, 3, 3, 3, 3, 3 };
  int exp[6] = { 243, 243, 243, 243, 243, 243 };
  int *res = made_massive(a, N);

  for (int i = 0; i < N; ++i)
    EXPECT_EQ(res[i], exp[i]);
}
