#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/bellman_ford.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_w<ll>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c);
    if (c >= 0) g[b].ep(a, c);
  }
  YES(bellman_ford<ll>(g, 0).fi.empty());
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}