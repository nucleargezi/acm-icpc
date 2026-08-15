#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/inc_scc.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/un/dsu.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, f, N);
  VEC(PII, es, M);
  Z ti = inc_scc(N, es);
  vc<vc<int>> v(M);
  FOR(i, M) if (ti[i] != M) v[ti[i]].ep(i);
  dsu g(N);
  mint s;
  FOR(t, M) {
    for (int i : v[t]) {
      Z [a, b] = es[i];
      a = g[a], b = g[b];
      if (a == b) continue;
      mint l = f[a], r = f[b];
      s += l * r;
      g.merge(a, b);
      f[g[a]] = l + r;
    }
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}