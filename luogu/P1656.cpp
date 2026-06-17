#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bridge.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, es, M);
  vc<vc<edge_id>> g(N);
  FOR(i, M) {
    Z &[a, b] = es[i];
    if (a > b) swap(a, b);
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  Z vis = bridge(g);
  vc<PII> rs;
  FOR(i, M) if (vis[i]) rs.ep(es[i]);
  sort(rs);
  for (var [a, b] : rs) print(a + 1, b + 1);
}

int main() {
  Yorisou();
  return 0;
}