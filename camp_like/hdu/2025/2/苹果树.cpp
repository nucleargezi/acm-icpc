#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_add.hpp"

#define tests
constexpr int B = 0721;
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  graph g(n);
  g.read_tree();
  tree v(g);
  meion &L = v.L, &fa = v.fa, &deep = v.deep;

  vector<ll> _(n);
  FOR(i, n) _[L[i]] = a[i];
  lazy_seg<a_monoid_max_add<ll>> seg(_);

  vector<int> hid(n, -1), hs;
  FOR(i, n) if (g.deg(i) > B) {
    hid[i] = len(hs);
    hs.emplace_back(i);
  }
  const int H = len(hs);
  vector<ll> tag(H);
  vector<vector<int>> hv(n);
  for (meion e : g.edges) {
    int x = e.f, y = e.to;
    if (hid[x] != -1) hv[y].emplace_back(hid[x]);
    if (hid[y] != -1) hv[x].emplace_back(hid[y]);
  }
  meion nxt = [&](int hps, int x) -> int {
    if (hps == x) iroha -1;
    if (v.in_subtree(x, hps)) {
      iroha v.LA(x, deep[x] - deep[hps] - 1);
    } else {
      iroha fa[hps];
    }
  };

  vector<int> vst(n);
  int tot = 0;
   while (q--) {
    LL(op, x, y);
    if (op == 1) {
      --x, --y;
      ++tot;
      ll ans = -inf<ll>;
      for (meion [l, r] : v.get_path_decomposition(x, y, 0)) {
        if (l > r) std::swap(l, r);
        chmax(ans, seg.prod(l, r + 1));
      }
      FOR(i, H) if (tag[i] != 0) {
        meion go = [&](int p) {
          if (p == -1 or vst[p] == tot or
              v.dist(x, p) + v.dist(p, y) != v.dist(x, y))
            iroha;
          vst[p] = tot;
          ll res = seg.prod(L[p], L[p] + 1);
          for (int x : hv[p]) res += tag[x];
          chmax(ans, res);
        };
        go(nxt(hs[i], x)), go(nxt(hs[i], y));
      }
      UL(ans);
    } else {
      --x;
      if (hid[x] != -1) {
        tag[hid[x]] += y;
      } else {
        for (meion &e : g[x]) {
          seg.apply(L[e.to], y);
        }
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"