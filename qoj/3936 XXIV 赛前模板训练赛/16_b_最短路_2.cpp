#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/sht/bellman_ford.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  vc<vc<edge_w<int>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c);
  }
  Z d = bellman_ford<ll>(g, s).fi;
  FOR(i, N) {
    if (i) put(' ');
    if (d[i] == -inf<ll>) put("-inf");
    else if (d[i] == inf<ll>) put("N/A");
    else put(d[i]);
  }
  print();
}

int main() {
  Yorisou();
  return 0;
}