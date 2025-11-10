#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/max_idx.hpp"

// #define tests
using LCT = LCT_monoid_commute<monoid_max_idx<int>>;
void Yorisou() {
  INT(N, M, Q);
  vector<tuple<int, int, int, int, int>> e;
  VEC(T3<int>, mp, M);
  vector<int> t(M);
  for (Z &[x, y, w] : mp) {
    --x, --y;
    if (x > y) swap(x, y);
  }
  FOR(i, Q) {
    INT(k, w);
    --k;
    Z [x, y, pw] = mp[k];
    e.ep(x, y, pw, t[k], i);
    mp[k] = {x, y, w};
    t[k] = i;
  }
  FOR(i, M) {
    Z [x, y, w] = mp[i];
    e.ep(x, y, w, t[i], Q);
  }
  const int sz = len(e);
  vector<int> I(sz);
  iota(all(I), 0);
  LCT lct(N + sz);
  FOR(i, sz) {
    Z [x, y, w, l, r] = e[i];
    lct.a[i + N].mx = {w, i};
  }
  ll ans = 0;
  vector<PII> st;
  Z f = [&](Z &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) return;
    ll cp = ans;
    int m = (l + r) >> 1, t = len(st);
    vector<int> li, ri;
    for (int i : I) {
      Z [x, y, w, pl, pr] = e[i];
      if (pl <= l and pr >= r) {
        if (lct.get_rt(x) == lct.get_rt(y)) {
          Z [mx, id] = lct.prod(x, y);
          if (mx > w) {
            Z [xx, yy, k, j, l] = e[id];
            ans -= mx;
            lct.cut(xx, id + N);
            lct.cut(yy, id + N);
            st.ep(0, id);
            goto Link;
          }
        } else {
        Link:
          ans += w;
          lct.link(x, i + N);
          lct.link(y, i + N);
          st.ep(1, i);
        }
      } else {
        if (pl < m) li.ep(i);
        if (pr > m) ri.ep(i);
      }
    }
    if (l + 1 == r) print(ans);
    else f(f, l, m, li), f(f, m, r, ri);
    while (len(st) > t) {
      Z [op, id] = pop(st);
      Z [x, y, w, l, r] = e[id];
      if (op == 1) lct.cut(x, id + N), lct.cut(y, id + N);
      else lct.link(x, id + N), lct.link(y, id + N);
    }
    ans = cp;
  };
  f(f, 0, Q, I);
}
#include "YRS/Z_H/main.hpp"