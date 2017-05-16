#include <iostream>
#include "kruskal.h"
#include "prim.h"
#include "graph.h"

int main() {
  Graph g, g2;
  Graph ostov;
  char q1[] = "example.txt";
  char q2[] = "example2.txt";

  // ������ ���� �� ������ ���������
  g = create_graph(q2);
  std::cout << "Created graph:" << std::endl << std::endl;
  Print(&g);
  // �������� ��������
  Kruskal(&g, &ostov);
  std::cout << "" << std::endl;
  std::cout << "Minimum spanning tree of the graph:" << std::endl << std::endl;
  Print(&ostov);
  std::cout << "" << std::endl;

  // ������������ ����������� ����� � ������

  char graph1[] = "C:\\Users\\������\\Desktop\\graph1.gv";
  char ostov1[] = "C:\\Users\\������\\Desktop\\ostov1.gv";
  char g_and_o[] = "C:\\Users\\������\\Desktop\\graph_and_ostov_1.gv";

  graph_to_gv(&g, graph1);
  ostov_to_gv(&ostov, ostov1);
  graph_and_ostov_to_gv(&g, &ostov, g_and_o);

  // ������ ���� �� ������� ���������
  g2 = Create_graph(q1);
  std::cout << "Created graph:" << std::endl << std::endl;
  Print(&g2);
  // �������� �����
  Prim(&g2, &ostov);
  std::cout << "" << std::endl;
  std::cout << "Minimum spanning tree of the graph:" << std::endl << std::endl;
  Print(&ostov);

  // ������������ ����������� ����� � ������

  char graph2[] = "C:\\Users\\������\\Desktop\\graph2.gv";
  char ostov2[] = "C:\\Users\\������\\Desktop\\ostov2.gv";
  char g_and_o_2[] = "C:\\Users\\������\\Desktop\\graph_and_ostov_2.gv";

  graph_to_gv(&g2, graph2);
  ostov_to_gv(&ostov, ostov2);
  graph_and_ostov_to_gv(&g2, &ostov, g_and_o_2);

  return 0;
}
