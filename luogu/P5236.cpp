#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/cactus/dist.hpp"

void Yorisou() {
  INT(N, M, Q);
  vc<vc<edge_w<int>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c), g[b].ep(a, c);
  }
  cactus_dist<ll, int> v(g);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(v.dist(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}