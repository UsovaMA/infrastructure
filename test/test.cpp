#include <gtest/gtest.h>
#include "add.h"

TEST(Addition, CanAddTwoNumbers) {
  EXPECT_EQ(add(2, 2), 4);
  EXPECT_EQ(add(-2, 2), 0);
}

TEST(Addition, CanSubTwoNumbers) {
  EXPECT_EQ(sub(2, 2), 0);
  EXPECT_EQ(sub(6, 2), 4);
}

TEST(Addition, CanMultTwoNumbers) {
  EXPECT_EQ(mult(2, 2), 4);
  EXPECT_EQ(mult(-2, 2), -4);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

