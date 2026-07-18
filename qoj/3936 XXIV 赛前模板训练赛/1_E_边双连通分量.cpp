#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bcc_e.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  FOR(i, M) {
    INT(a, b);
    g[a].ep(b, i), g[b].ep(a, i);
  }
  Z [c, id] = bcc_e(g);
  vc<vc<int>> bcc(c);
  FOR(i, N) bcc[id[i]].ep(i);
  print(c);
  FOR(i, c) print(si(bcc[i]), bcc[i]);
}

int main() {
  Yorisou();
  return 0;
}