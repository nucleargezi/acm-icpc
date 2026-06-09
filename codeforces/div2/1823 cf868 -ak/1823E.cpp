#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

int ke(int l, int r, int x) { return x >= l + r ? 0 : x / l; }

void Yorisou() {
  INT(N, l, r);
  dsu g(N);
  FOR(N) {
    INT(a, b);
    --a, --b;
    g.merge(a, b);
  }
  int x = 0;
  FOR(i, N) if (g[i] == i) x ^= ke(l, r, g.size(i));
  Alice(x);
}

int main() {
  Yorisou();
  return 0;
}