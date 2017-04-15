#include "min_way.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  cout << "Find way from (0,0) to (4,5): ";
  char* result_way = way(4, 5);
  cout << result_way << endl << endl;
  cout << "Find way from (0,0) to (-4,5): ";
  result_way = way(-4, 5);
  cout << result_way << endl << endl;
  cout << "Find way from (0,0) to (4,-5): ";
  result_way = way(4, -5);
  cout << result_way << endl << endl;
  cout << "Find way from (0,0) to (-4,-5): ";
  result_way = way(-4, -5);
  cout << result_way << endl << endl;
  cout << "Find way from (0,0) to (0,0): ";
  result_way = way(0, 0);
  cout << result_way << endl << endl;
  cout << "Find way from (0,0) to (4,-55): ";
  result_way = way(4, -55);
  cout << result_way << endl << endl;
}
