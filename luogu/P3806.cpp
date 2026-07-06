#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"
#include "YRS/ttr/tree_dec.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<edge_w<int>>> g(N);
  hashmap<int> mp;
  FOR(N - 1) {
    INT(a, b, c);
    --a, --b;
    if (a > b) swap(a, b);
    g[a].ep(b, c);
    g[b].ep(a, c);
    mp[ull(a) << 32 | b] = c;
  }

  VEC(int, q, Q);
  vc<char> rs(Q);
  Z [fa, V] = dec_pr(g);
  set<int> se;
  vc<int> dis(N);
  dec1(fa, V, [&](const vc<int> &fa, const vc<int> &vs, int l, int r, int L, int R) -> void {
    se.clear();
    int sz = si(fa);
    dis.assign(sz, 0);
    FOR(i, 1, sz) {
      int x = vs[i], f = fa[i], p = vs[f];
      dis[i] = dis[f] + mp[ull(min(x, p)) << 32 | max(x, p)];
    }
    FOR(i, l, r) se.eb(dis[i]);
    FOR(i, L, R) FOR(k, Q) if (not rs[k] and se.contains(q[k] - dis[i])) rs[k] = 1;
  });
  for (bool f : rs) print(f ? "AYE" : "NAY");
}

int main() {
  Yorisou();
  return 0;
}