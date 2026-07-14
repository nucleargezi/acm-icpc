#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/gg/matrix_tree.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  vc<T3<int>> es;
  retsu<int> id(N, M);
  int t = 0;
  FOR(i, N) FOR(k, M) if (a[i][k] == '.') {
    id[i][k] = t++;
    if (i and a[i - 1][k] == '.') es.ep(id[i][k], id[i - 1][k], 1);
    if (k and a[i][k - 1] == '.') es.ep(id[i][k], id[i][k - 1], 1);
  }
  print(matrix_tree(t, 0, es, 0, 1'000'000'000));
}

int main() {
  Yorisou();
  return 0;
}