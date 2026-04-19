#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/tr/hld.hpp"

void Yorisou() {
  INT(N, Q);
  graph g(N);
  FOR(i, 1, N) {
    INT(f);
    g.add(f, i);
  }
  g.build();
  hld v(g);
  FOR(Q) {
    INT(x, y);
    print(v.lca(x, y));
  }
}

int main() {
  Yorisou();
  return 0;
}