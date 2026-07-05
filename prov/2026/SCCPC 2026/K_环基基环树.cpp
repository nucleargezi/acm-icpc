#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bridge.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id>> g(N);
  vc<PII> es(M);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    es[i] = {a, b};
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  vc<char> br(bridge(g));
  
  g.assign(N, {});
  vc<int> in(N);
  dsu f(N);
  FOR(i, M) if (not br[i]) {
    var [a, b] = es[i];
    g[a].ep(b, i);
    g[b].ep(a, i);
    f.merge(a, b);
    ++in[a], ++in[b];
  }

  Z gp = f.group();
  int sz = si(gp), t = 0, rid;
  vc<int> id(N);
  FOR(i, sz) if (si(gp[i]) > 1) {
    bool f = 1;
    for (int x : gp[i]) f &= in[x] == 2;
    if (f) {
      for (int x : gp[i]) id[x] = t;
      ++t;
    } else {
      rid = i;
    }
  }

  var ri = gp[rid];
  f.reset();
  for (int x : ri) if (in[x] == 2) {
    for (int t : g[x]) f.merge(t, x);
  }
  gp = f.group();
  sz = si(gp);
  FOR(i, sz) if (si(gp[i]) > 2) {
    for (int x : gp[i]) id[x] = t;
    ++t;
  }

  vc<PII> rs;
  for (var [a, b] : es) if (id[a] != id[b]) rs.ep(id[a], id[b]);
  print(si(rs));
  for (var [a, b] : rs) print(a + 1, b + 1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}