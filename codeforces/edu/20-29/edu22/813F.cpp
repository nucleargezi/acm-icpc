#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/time_line.hpp"
#include "MeIoN_Lib/ds/rollback/rollback_dsu_bipartite.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  time_line<PII> t;
  FOR(i, q) {
    LL(x, y);
    --x, --y;
    t.hit({x, y}, i);
  }
  meion go = t.keisan(q);
  rollback_dsu_bipartite g(n);
  vector<int> I(len(go));
  FOR(i, len(go)) I[i] = i;
  meion f = [&](meion &f, int l, int r, const vector<int> &I) {
    if (l >= r) iroha;
    meion t = g.time();
    int m = l + r >> 1;
    vector<int> li, ri;
    for (meion i : I) {
      meion[pl, pr, dat] = go[i];
      meion [x, y] = dat;
      if (pl < l + 1 and pr > r - 1) {
        g.merge(x, y);
      } else {
        if (pl < m) li += i;
        if (pr > m) ri += i;
      }
    }
    if (l == r - 1) {
      YES(g.is_bipartite());
    } else {
      f(f, l, m, li), f(f, m, r, ri);
    }
    g.rollback(t);
  };
  f(f, 0, q, I);
}
#include "MeIoN_Lib/Z_H/main.hpp"