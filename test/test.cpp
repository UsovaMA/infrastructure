#include <gtest/gtest.h>
#include <vector>
#include "building.h"

TEST(built_groups, example_1) {
  
  std::vector < std::pair < int, int > > enemies;
  enemies.push_back(std::make_pair(0, 1));
  enemies.push_back(std::make_pair(1, 2));
  enemies.push_back(std::make_pair(0, 2));
  std::vector < int > result = built_groups(enemies, 3);

  std::vector < int > expect;
  expect.push_back(0);
  expect.push_back(1);
  expect.push_back(2);

  EXPECT_EQ(result, expect); 
}

TEST(built_groups, example_2) {
  std::vector < std::pair < int, int > > enemies;
  enemies.push_back(std::make_pair(0, 1));
  enemies.push_back(std::make_pair(1, 2));
  enemies.push_back(std::make_pair(0, 2));
  enemies.push_back(std::make_pair(3, 4));
  enemies.push_back(std::make_pair(4, 2));
  std::vector < int > result = built_groups(enemies, 5);

  std::vector < int > expect;
  expect.push_back(0);
  expect.push_back(1);
  expect.push_back(2);
  expect.push_back(0);
  expect.push_back(1);

  EXPECT_EQ(result, expect);
}

TEST(built_groups, example_3) {
  std::vector < std::pair < int, int > > enemies;
  enemies.push_back(std::make_pair(0, 1));
  enemies.push_back(std::make_pair(1, 2));
  enemies.push_back(std::make_pair(2, 3));
  enemies.push_back(std::make_pair(3, 4));
  enemies.push_back(std::make_pair(4, 5));
  std::vector < int > result = built_groups(enemies, 6);

  std::vector < int > expect;
  expect.push_back(0);
  expect.push_back(1);
  expect.push_back(0);
  expect.push_back(1);
  expect.push_back(0);
  expect.push_back(1);

  EXPECT_EQ(result, expect);
}

TEST(built_groups, example_4) {
  std::vector < std::pair < int, int > > enemies;
  std::vector < int > result = built_groups(enemies, 6);

  std::vector < int > expect;
  expect.push_back(0);
  expect.push_back(0);
  expect.push_back(0);
  expect.push_back(0);
  expect.push_back(0);
  expect.push_back(0);

  EXPECT_EQ(result, expect);
}

TEST(built_groups, example_5) {
  std::vector < std::pair < int, int > > enemies;
  std::vector < int > result = built_groups(enemies, 0);
  std::vector < int > expect;

  EXPECT_EQ(result, expect);
}
