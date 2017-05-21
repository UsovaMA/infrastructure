#include "building.h"
#include <iostream>

int main() {
  std::vector < std::pair < int, int > > enemies;

  std::cout << "Task: built minimal number of groups for {1, 2 .. 5}." << std::endl;

  std::cout << std::endl << "Enemies:" << std::endl;
  enemies.push_back(std::make_pair(0, 1));
  enemies.push_back(std::make_pair(1, 2));
  enemies.push_back(std::make_pair(0, 2));
  enemies.push_back(std::make_pair(3, 4));
  enemies.push_back(std::make_pair(4, 2));
  int size = enemies.size();
  for (int i = 0; i < size; i++) {
    std::cout << enemies[i].first + 1 << " and " << enemies[i].second + 1;
    std::cout << ";" << std::endl;
  }

  std::cout << std::endl << "Result: " << "(";
  std::vector < int > result = built_groups(enemies, 5);
  int i;
  int res_size = result.size();
  for (i = 0; i < res_size - 1; i++) {
    std::cout << result[i] + 1 << ", ";
  }
  std::cout << result[i] + 1 << ")" << std::endl;

  return 0;
}
