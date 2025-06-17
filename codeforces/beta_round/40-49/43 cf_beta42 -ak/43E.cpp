#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, s);
  vector<vector<PLL>> v(n);
  FOR(i, n) {
    LL(sz);
    v[i].resize(sz);
    IN(v[i]);
    FOR(k, sz) swap(v[i][k].first, v[i][k].second);
    FOR(k, 1, sz) v[i][k].first += v[i][k - 1].first;
  }
  ll ans = 0;
  FOR(i, n) FOR(k, i + 1, n) {
    ll a = 0, b = 0, t = 0;
    int f = 0;
    while (a != s and b != s) {
      meion [t0, c0] = *upper(v[i], PLL{t, inf<ll>});
      meion [t1, c1] = *upper(v[k], PLL{t, inf<ll>});
      ll nx = MIN(t0, t1);
      a += (nx - t) * c0;
      b += (nx - t) * c1;
      t = nx;
      if (f == 1 and a < b) ++ans;
      if (f == -1 and a > b) ++ans;
      f = a > b ? 1 : a < b ? -1 : f;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"