#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M, K);
  dsu g(N);
  vc<int> f(N, -1);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g.merge(a, b);
    --f[a], --f[b];
  }
  FOR(i, N) f[i] += g.size(i);
  FOR(K) {
    INT(a, b);
    --a, --b;
    if (g[a] == g[b]) --f[a], --f[b];
  }
  print(f);
}

int main() { Yorisou(); }