#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/bellman_ford.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_w<int>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, -c);
  }
  Z d = bellman_ford<int>(g, 0).fi;
  print(d[N - 1] == inf<int> ? -1 : -d[N - 1]);
}

int main() {
  Yorisou();
  return 0;
}