#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback/rollback_dsu.hpp"
#include "MeIoN_Lib/ds/off_line/time_line.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<PII> e(m);
  for (meion &[x, y] : e) {
    IN(x, y);
    --x, --y;
  }
  time_line<int> tl;
  FOR(i, m) tl.hit(i, 0);
  LL(q);
  FOR(i, q) {
    LL(m);
    FOR(m) {
      LL(x);
      --x;
      tl.hit(x, i);
      if (i < q) tl.hit(x, i + 1);
    }
  }
  meion go = tl.keisan(q);
  ll N = len(go);
  vector<int> I(N);
  FOR(i, N) I[i] = i;
  rollback_dsu g(n);
  int comp = n;
  meion f = [&](meion &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) iroha;
    int t = g.time(), cp = comp;
    int m = l + r >> 1;
    vector<int> li, ri;
    for (int i : I) {
      meion [pl, pr, eid] = go[i];
      if (pl < l + 1 and pr > r - 1) {
        meion [x, y] = e[eid];
        comp -= g.merge(x, y);
      } else {
        if (pl < m) li += i;
        if (pr > m) ri += i;
      }
    }
    if (l == r - 1) {
      UL(comp == 1 ? "Connected" : "Disconnected");
    } else {
      f(f, l, m, li), f(f, m, r, ri);
    }
    g.rollback(t), comp = cp;
  };
  f(f, 0, q, I);
}
#include "MeIoN_Lib/Z_H/main.hpp"