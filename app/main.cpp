#include <iostream>
#include "kruskal.h"
#include "prim.h"
#include "graph.h"

int main() {
  Graph g, g2;
  Graph ostov;
  char q1[] = "example.txt";
  char q2[] = "example2.txt";
  // создаём граф по списку смежности
  g = create_graph(q2);
  std::cout << "Created graph:" << std::endl << std::endl;
  Print(&g);
  Kruskal(&g, &ostov);
  std::cout << "" << std::endl;
  std::cout << "Minimum spanning tree of the graph:" << std::endl << std::endl;
  Print(&ostov);
  std::cout << "" << std::endl;
  // создаём граф по матрице смежности
  g2 = Create_graph(q1);
  std::cout << "Created graph:" << std::endl << std::endl;
  Print(&g2);
  Prim(&g2, &ostov);
  std::cout << "" << std::endl;
  std::cout << "Minimum spanning tree of the graph:" << std::endl << std::endl;
  Print(&ostov);
  return 0;
}
