#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/doubling.hpp"

void Yorisou() {
  INT(N, Q, t);
  --t;
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  doubling v(g, t);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(v.lca(a, b) + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}