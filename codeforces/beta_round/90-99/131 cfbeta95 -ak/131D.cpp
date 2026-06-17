#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/unicycle.hpp"
#include "YRS/gg/sht/bfs1.hpp"

void Yorisou() {
  INT(N);
  vc<vc<edge_id>> g(N);
  FOR(i, N) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  unicycle v(g);
  print(bfs1(g, v.cc).fi);
}

int main() {
  Yorisou();
  return 0;
}