#include "search_in_tree.h"
#include <iostream>

int main() {
  CNode* tree = create_tree_for_tests();

  std::cout << std::endl << "Tree" << std::endl << std::endl;
  print_tree(tree, 3);
  std::cout << "" << std::endl;

  std::cout << "Tree with adress" << std::endl << std::endl;
  print_tree_with_adress(tree, 3);
  CNode** res = find(&tree, 9);
  *res = new CNode(9);
  CNode* new_search = *(find(&tree, 9));
  std::cout << std::endl <<
    "Tree with adress after adding an element on found position"
    << std::endl << std::endl;
  print_tree_with_adress(tree, 3);
}
