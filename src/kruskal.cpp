/*         Построение минимального остовного дерева графа       */
/*                        Алгоритм Краскала                     */
/*      Вход: граф построенный по списку смежности из файла     */
/* Выход: Пары вершин, составляющих минимальное остовное дерево */

#include <stack>
#include "kruskal.h"
#include "disjoint_sets.h"
#include <stdexcept>

using std::logic_error;

void Kruskal(Graph *g, Graph *ostov) {
  std::stack <edge> st;
  Disjoint_Sets s(g->N);
  int N = g->N;
  if (!N)
    throw logic_error("Error: there in not verix in graph.\n");
  if (!g->edge_N)
    throw logic_error("Error: there in not edges in graph.\n");
  ostov->N = N;
  ostov->edge_N = N - 1;
  ostov->edges = new edge[N - 1];
  for (int i = 0; i < N; i++)
    s.make_set(i);
  for (int i = 0; i < g->edge_N; i++)
    st.push(g->edges[i]);
  int i = 0;
  while ((st.empty() != 1) && (i < N - 1)) {
    edge tmp = st.top();
    st.pop();
    if (s.find_set(static_cast<int>(tmp.x-65)) != s.find_set(static_cast<int>(tmp.y-65))) {
      ostov->edges[i] = tmp;
      i++;
      s.union_sets(static_cast<int>(tmp.x - 65), static_cast<int>(tmp.y - 65));
    }
  }
}
