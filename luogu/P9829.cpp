#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ttr/doubling.hpp"
#include "YRS/gg/bct.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  STR(s);
  FOR(i, N) s[i] = s[i] == 'H';
  vc<PII> es, ee;
  FOR(M) {
    INT(a, b);
    if (s[a] == s[b]) {
      es.ep(a, b);
      continue;
    }
    g[a].ep(b), g[b].ep(a);
    ee.ep(a, b);
  }
  vc<vc<int>> gg = bct(g);
  g.assign(N, {});
  dsu f(N);
  for (var [a, b] : ee) f.merge(a, b);
  doubling db(gg);

  for (Z [a, b] : es) if (f[a] == f[0] and f[b] == f[0]) {
    if (a == 0 or b == 0) return yes();
    a = db.jump(a, 0, 1);
    b = db.jump(b, 0, 1);
    int c = db.lca(a, b);
    if (c == a or b == c) return yes();
  }
  no();
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}