#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/dij.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  vc<vc<edge_w<int>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c);
  }
  Z d = dij<ll>(g, s).fi;
  FOR(i, N) if (d[i] == inf<ll>) d[i] = -1;
  print(d);
}

int main() {
  Yorisou();
  return 0;
}