#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback/rollback_dsu_bipartite.hpp"

void before() {}

// #define tests
using dsu = rollback_dsu_bipartite;
void Yorisou() {
  LL(n, m, k);
  vector<T4<int>> es(m);
  for (meion &[l, r, x, y] : es) {
    IN(x, y, l, r);
    --x, --y;
  }
  vector<int> I(m);
  FOR(i, m) I[i] = i;
  dsu g(n);
  meion f = [&](meion &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) iroha;
    meion t = g.time();
    int m = l + r >> 1;
    vector<int> li, ri;
    for (int i : I) {
      meion [pl, pr, x, y] = es[i];
      if (pl >= pr) continue;
      if (pl < l + 1 and pr > r - 1) {
        g.merge(x, y);
      } else {
        if (pl < m) li += i;
        if (pr > m) ri += i;
      }
    }
    if (l == r - 1) {
      Yes(g.get_c() == 0);
    } else {
      f(f, l, m, li), f(f, m, r, ri);
    }
    g.rollback(t);
  };
  f(f, 0, k, I);
}
#include "MeIoN_Lib/Z_H/main.hpp"