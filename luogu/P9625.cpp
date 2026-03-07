#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N, M);
  vc<PII> es;
  hashmap<int> eid(M);
  FOR(M) {
    INT(x, y);
    if (x == y) continue;
    --x, --y;
    if (x > y) swap(x, y);
    if (not eid.contains(ull(x) << 32 | y)) {
      eid[ull(x) << 32 | y] = len(es);
      es.ep(x, y);
    }
  }
  dsu g(N);
  lct_bs lct(N);
  vc<int> in(N);
  M = len(es);
  vc<u8> vis(M);
  FOR(i, M) {
    Z [x, y] = es[i];
    if (g.merge(x, y)) {
      lct.link(x, y);
      ++in[x], ++in[y];
      vis[i] = 1;
    }
  }

  Z Yes = [&]() {
    print("Yes");
    FOR(i, M) if (vis[i]) print(es[i].fi + 1, es[i].se + 1);
  };

  if (g.count() != 1) return print("No");
  if (QMAX(in) <= N / 2) return Yes();

  int rt = max_element(all(in)) - bg(in);
  FOR(i, M) if (not vis[i]) {
    int x = es[i].fi, y = es[i].se;
    if (x == rt or y == rt) continue;
    lct.evert(rt);
    if (lct.lca(x, y) != rt) continue;

    lct.evert(x);
    int al = lct.get_fa(rt);
    lct.evert(y);
    int ar = lct.get_fa(rt);
    if (in[al] < in[ar]) swap(al, ar), swap(x, y);
    lct.cut(rt, al);
    --in[rt];
    --in[al];
    int ls = min(rt, al), rs = ls ^ al ^ rt;
    vis[eid[ull(ls) << 32 | rs]] = 0;

    lct.link(x, y);
    ++in[x];
    ++in[y];
    vis[i] = 1;
    if (in[rt] <= N / 2) break;
  }
  if (QMAX(in) <= N / 2) return Yes();
  print("No");
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"