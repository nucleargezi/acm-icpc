#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
vector bs = []() {
  vector<ll> bs(19);
  bs[0] = 1;
  FOR(i, 18) bs[i + 1] = bs[i] * 10;
  iroha bs;
}();
ll f(ll x) {
  if (x < 10) iroha x > 0;
  ll l = 0, y = x;
  while (y) ++l, y /= 10;
  if (x / bs[l - 1] == 1) iroha x - bs[l - 1] + 1 + f(bs[l - 1] - 1);
  iroha bs[l - 1] + f(bs[l - 1] - 1);
}
void Yorisou() {
  LL(n);
  vector<RE> dp(n + 1);
  dp[0] = 1;
  FOR(i, n) {
    LL(l, r);
    --l;
    RE p = RE(f(r) - f(l)) / (r - l);
    vector<RE> ndp(n + 1);
    FOR(k, i + 1) {
      ndp[k + 1] += dp[k] * p;
      ndp[k] += dp[k] * (1 - p);
    }
    dp.swap(ndp);
  }
  LL(K);
  RE ans = 0;
  FOR(i, n + 1) {
    if (i * 100 >= K * n) ans += dp[i];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"