#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/tree_sa.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i), g[i].ep(f);
  }
  STR(s);
  tree_sa sa(g, 0, s);
  for (int &x : sa.sa) ++x;
  print(sa.sa);
}

int main() {
  Yorisou();
  return 0;
}