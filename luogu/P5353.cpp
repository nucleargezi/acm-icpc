#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/tree_sa.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
    g[i].ep(f);
  }
  STR(s);
  tree_sa tsa(g, 0, {all(s)});
  for (int &x : tsa.sa) ++x;
  print(tsa.sa);
}

int main() {
  Yorisou();
  return 0;
}