#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M17;
void Yorisou() {
  LL(n);
  VEC(ll, x, n);
  VEC(ll, y, n);
  ll N = SUM(x), s = 0;
  vector<mint> dp(N + 1);
  dp[0] = 1;
  FOR(i, n) {
    vector<mint> ndp(N + 1);
    FOR(k, s + 1) {
      FOR(j, MIN(s + x[i] - k, y[i]) + 1) {
        ndp[k + j] += dp[k] * C<mint>(s + x[i] - k, j);
      }
    }
    s += x[i];
    dp.swap(ndp);
  }
  mint ans = dp[N] * fact<mint>(N);
  for (ll x : x) ans *= fact_inv<mint>(x);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"