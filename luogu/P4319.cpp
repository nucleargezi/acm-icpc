#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/lct/lct_monoid.hpp"
#include "YRS/ds/monoid/max_idx.hpp"

// #define tests
using DS = LCT_monoid_commute<monoid_max_idx<int>>;
void Yorisou() {
  INT(N);
  vector<tuple<int, int, int, int, int>> e(N - 1);
  for (Z &[x, y, w, l, r] : e) {
    IN(x, y, w);
    --x, --y;
    l = 0, r = 32766;
  }
  INT(Q);
  FOR(Q) {
    INT(x, y, w, l, r);
    --x, --y, --l;
    e.ep(x, y, w, l, r);
  }
  DS lct(N + N - 1 + Q);
  for (int t = N; Z [x, y, w, l, r] : e) {
    lct[t]->mx = {w, t - N};
    ++t;
  }
  vector<int> I(N - 1 + Q);
  iota(all(I), 0);
  vector<PII> st;
  ll ans = 1;
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
  f(f, 0, 32766, I);
}
#include "YRS/Z_H/main.hpp"