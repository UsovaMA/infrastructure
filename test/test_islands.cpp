#include <gtest/gtest.h>
#include "islands.h"

/*
00011100
00010100
00010100
00000100
00100100
01010100
00000100
00010100
*/

TEST(ISLANDS, the_islands_are_drowning_correctly_DS) {
  std::vector<std::vector<int>> m(8, std::vector<int>(8, 0));
  m[0][5] = 1;
  m[1][5] = 1;
  m[2][5] = 1;
  m[3][5] = 1;
  m[4][5] = 1;
  m[5][5] = 1;
  m[6][5] = 1;
  m[7][5] = 1;

  m[0][3] = 1;
  m[0][4] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[4][2] = 1;
  m[4][3] = 1;
  m[5][1] = 1;
  m[5][3] = 1;
  m[7][3] = 1;

  std::vector<std::vector<int>> exp = m;
  exp[4][2] = 0;
  exp[4][3] = 0;
  exp[5][1] = 0;
  exp[5][3] = 0;

  std::vector<std::vector<int>> res;
  res = PercolationForDS(m);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      EXPECT_EQ(exp[i][j], res[i][j]);
}

TEST(ISLANDS, the_islands_are_drowning_correctly_BFS) {
  std::vector<std::vector<int>> m(8, std::vector<int>(8, 0));
  m[0][5] = 1;
  m[1][5] = 1;
  m[2][5] = 1;
  m[3][5] = 1;
  m[4][5] = 1;
  m[5][5] = 1;
  m[6][5] = 1;
  m[7][5] = 1;

  m[0][3] = 1;
  m[0][4] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[4][2] = 1;
  m[4][3] = 1;
  m[5][1] = 1;
  m[5][3] = 1;
  m[7][3] = 1;

  std::vector<std::vector<int>> exp = m;
  exp[4][2] = 0;
  exp[4][3] = 0;
  exp[5][1] = 0;
  exp[5][3] = 0;

  std::vector<std::vector<int>> res;
  res = PercolationForBFS(m);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      EXPECT_EQ(exp[i][j], res[i][j]);
}

TEST(ISLANDS, ñan_work_in_the_absence_of_islands_DS) {
  std::vector<std::vector<int>> m(8, std::vector<int>(8, 0));
  m[0][5] = 1;
  m[1][5] = 1;
  m[2][5] = 1;
  m[3][5] = 1;
  m[4][5] = 1;
  m[5][5] = 1;
  m[6][5] = 1;
  m[7][5] = 1;

  m[0][3] = 1;
  m[0][4] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[7][3] = 1;

  std::vector<std::vector<int>> res = PercolationForDS(m);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      EXPECT_EQ(m[i][j], res[i][j]);
}

TEST(ISLANDS, ñan_work_in_the_absence_of_islands_BFS) {
  std::vector<std::vector<int>> m(8, std::vector<int>(8, 0));
  m[0][5] = 1;
  m[1][5] = 1;
  m[2][5] = 1;
  m[3][5] = 1;
  m[4][5] = 1;
  m[5][5] = 1;
  m[6][5] = 1;
  m[7][5] = 1;

  m[0][3] = 1;
  m[0][4] = 1;
  m[1][3] = 1;
  m[2][3] = 1;
  m[7][3] = 1;

  std::vector<std::vector<int>> res = PercolationForBFS(m);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      EXPECT_EQ(m[i][j], res[i][j]);
}
