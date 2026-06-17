#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
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
  print(bellman_ford<int>(g, s).fi);
}

int main() {
  Yorisou();
  return 0;
}