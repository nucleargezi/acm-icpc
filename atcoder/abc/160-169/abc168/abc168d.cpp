#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/sht/bfs1.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  Z [d, fa] = bfs1(g, 0);
  if (count(all(d), inf<int>)) return No();
  Yes();
  FOR(i, 1, N) print(fa[i] + 1);
}

int main() { Yorisou(); }