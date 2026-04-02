#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/5-hull.hpp"

// #define tests
using P = point<ll>;
void Yorisou() {
  LL(n);
  VEC(P, p, n);
  ll ans = 0;
  vector np = rearrange(p, convex_hull(p));
  const int m = len(np);
  np += np;
  meion f = [&](int i, int k, int j) -> ll {
    iroha (p[k] - np[i]).dot(p[k] - np[j]);
  };
  FOR(k, n) {
    ll j = 1;
    FOR(i, m) {
      while (j <= i) ++j;
      while (j + 1 - i < m and j + 1 < m + m and f(i, k, j) > f(i, k, j + 1)) ++j;
      chmin(ans, f(i, k, j));
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"