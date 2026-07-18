#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bridge.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  VEC(PII, es, M);
  FOR(i, M) {
    Z [a, b] = es[i];
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  Z vis = bridge(g);
  FOR(i, M) if (vis[i]) print(es[i]);
}

int main() {
  Yorisou();
  return 0;
}