#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, c, n);
  vector a(n, vector<ll>(m));
  FOR(i, m) {
    LL(sz);
    FOR(sz) {
      LL(x);
      ++a[--x][i];
    }
  }
  ll ans = inf<ll>;
  FOR(msk, 1 << n + n) {
    vector<ll> v(m);
    ll cost = 0;
    FOR(i, n + n) if (msk >> i & 1) {
      cost += c[i % n];
      if (cost >= ans) break;
      FOR(k, m) v[k] += a[i % n][k];
    }
    if (QMIN(v) > 1) chmin(ans, cost);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"