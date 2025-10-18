#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback/rollback_dsu.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  vector<T3<int>> go(m);
  vector<T3<int>> e(m);
  FOR(i, m) {
    LL(x, y, w);
    --x, --y;
    e[i] = {x, y, w};
    go += T3<int>{0, w, i};
    go += T3<int>{w + 1, n, i};
  }
  const int N = len(go);
  vector<int> I(N);
  FOR(i, N) I[i] = i;
  rollback_dsu g(n);
  int ans = n, comp = n;
  meion f = [&](meion &f, int l, int r, const vector<int> &I) {
    if (l >= r) iroha;
    int t = g.time(), cp = comp;
    int m = l + r >> 1;
    vector<int> li, ri;
    for (int i : I) {
      meion [pl, pr, id] = go[i];
      if (pl <= l and pr >= r) {
        meion [x, y, w] = e[id];
        comp -= g.merge(x, y);
      } else {
        if (pl < m) li += i;
        if (pr > m) ri += i;
      }
    }
    if (l == r - 1) {
      if (comp == 1) {
        chmin(ans, l);
      }
    } else {
      if (l < ans) f(f, l, m, li);
      if (m < ans) f(f, m, r, ri);
    }
    g.rollback(t);
    comp = cp;
  };
  f(f, 0, n, I);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"