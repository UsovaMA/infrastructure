#include <gtest/gtest.h>
#include "min_way.h"

bool test_1(int x, int y) {
  int x0 = 0, y0 = 0;
  int step = 1;
  char* ch = way(x, y);
  for (int i = 0; ch[i] != '\0'; ++i) {
    if (ch[i] == 'N')
      y0 += step;
    if (ch[i] == 'S')
      y0 -= step;
    if (ch[i] == 'W')
      x0 -= step;
    if (ch[i] == 'E')
      x0 += step;
    step++;
  }
  return ((x == x0) && (y == y0));
}

TEST(Find_Way, can_find) {
  for (int x = 1; x < 50; ++x)
    for (int y = 1; y < 50; ++y) {
      EXPECT_TRUE(test_1(x, y));
      EXPECT_TRUE(test_1(-x, y));
      EXPECT_TRUE(test_1(x, -y));
      EXPECT_TRUE(test_1(-x, -y));
    }
}
