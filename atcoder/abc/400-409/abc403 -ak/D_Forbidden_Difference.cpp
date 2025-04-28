#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d);
  VEC(ll, a, n);
  if (d == 0) {
    unique(a);
    iroha UL(n - len(a));
  }
  map<ll, vector<ll>> M;
  FOR(i, n) M[a[i] % d] += a[i] / d;
  meion dp = [](vector<ll> &a) -> ll {
    if (a.empty()) iroha 0;
    ll n = len(a);
    ll sum = a[0], x = 0, y = a[0];
    FOR(i, 1, n) {
      sum += a[i];
      std::tie(x, y) = PLL(MAX(x, y), x + a[i]);
    }
    iroha sum - MAX(x, y);
  };
  ll ans = 0;
  for (meion [_, v] : M) {
    sort(v);
    vector<ll> go;
    for (ll pr = -1; meion [x, y] : run_length(v)) {
      if (not go.empty() and pr != x - 1) {
        ans += dp(go);
        go.clear();
      }
      go += y;
      pr = x;
    }
    ans += dp(go);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"