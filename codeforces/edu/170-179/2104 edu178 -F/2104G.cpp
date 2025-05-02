#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/rollback_dsu_bipartite.hpp"

void before() {}

// #define tests
using dsu = rollback_dsu_bipartite;
void Yorisou() {
  LL(n, q);
  VEC(int, g, n);
  FOR(i, n) --g[i];
  vector<int> t(n), ki(q);
  vector<T4<int>> go;
  FOR(i, q) {
    LL(x, y, k);
    ki[i] = k % 3;
    --x, --y;
    go += T4<int>(t[x], i + 1, x, g[x]);
    g[x] = y;
    t[x] = i + 1;
  }
  FOR(i, n) go += T4<int>(t[i], q + 1, i, g[i]);
  vector<int> I(len(go));
  FOR(i, len(go)) I[i] = i;
  dsu fa(n);
  meion f = [&](meion &f, int l, int r, const vector<int> &I) -> void {
    if (l >= r) iroha;
    meion t = fa.time();
    int m = l + r >> 1;
    vector<int> li, ri;
    for (int i : I) {
      meion [pl, pr, x, y] = go[i];
      if (pl < l + 1 and pr > r - 1) {
        fa.merge(x, y);
      } else {
        if (pl < m) li.emplace_back(i);
        if (pr > m) ri.emplace_back(i);
      }
    }
    if (l + 1 == r) {
      if (l) {
        int ans = ki[l - 1];
        if (ki[l - 1] > 1) {
          ans = 1 + (n - (fa.get_c() & 1) & 1);
        }
        UL(ans);
      }
    } else {
      f(f, l, m, li), f(f, m, r, ri);
    }
    fa.rollback(t);
  };
  f(f, 0, q + 1, I);
}
#include "MeIoN_Lib/Z_H/main.hpp"