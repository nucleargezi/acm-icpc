#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bcc_v_e.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  vc<PII> ee(M);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    ee[i] = {a, b};
    g[a].ep(b, i), g[b].ep(a, i);
  }
  Z [vs, es] = bcc_v_e(g);
  vc<int> in(N), ii(N), rs(N);
  FOR(i, si(vs)) if (si(vs[i]) > 2) {
    var v = vs[i], e = es[i];
    for (int i : e) {
      var [a, b] = ee[i];
      ++ii[a], ++ii[b];
    }
    for (int x : v) rs[x] += ii[x] / 2, ii[x] = 0;
  }
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}