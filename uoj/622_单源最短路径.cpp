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
  Z dis = dij<ll>(g, s).fi;
  FOR(i, N) if (dis[i] == inf<ll>) dis[i] = -1;
  print(dis);
}

int main() { Yorisou(); }