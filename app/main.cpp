#include "create_tree.h"
#include <iostream>

int main() {
  const int size = 6;
  int A[size] = { 1, 3, 4, 5, 6, 7 };


  CNode* tree_1 = create_tree(A, size);
  std::cout << std::endl << "Created tree" << std::endl << std::endl;
  print_tree(tree_1, 4);

  CNode* tree_2 = create_tree_with_recursion(A, 0, size - 1);
  std::cout << std::endl <<
    "Created tree with recursion" << std::endl << std::endl;
  print_tree(tree_2, 4);
  std::cout << "" << std::endl;

  std::cout << std::endl << "Another view" << std::endl << std::endl;
  PrintTree(tree_1);
  std::cout << "" << std::endl;

  std::cout << std::endl << "Use search" << std::endl << std::endl;
  CNode** res = find(&tree_1, 8);
  *res = new CNode(8);
  std::cout << std::endl <<
    "Tree after adding an element 8 on found position"
    << std::endl << std::endl;
  print_tree(tree_1, 4);
  PrintTree(tree_1);
  return 0;
}
