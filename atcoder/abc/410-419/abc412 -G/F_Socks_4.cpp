#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, K);
  --K;
  VEC(ll, a, n);
  const ll N = QMAX(a);
  vector<ll> v(N + 1, 0);
  for (ll x : a) v[x]++;
  vector<ll> c(N + 3, 0);
  FOR_R(i, 1, N + 1) {
    c[i] = i * v[i] + c[i + 1];
  }
  vector<mint> dp(N + 1, 0);
  mint sa = SUM(a);
  dp[N] = sa / N;
  mint s = 0;
  FOR_R(k, 1, N) {
    if (k + 2 <= N) s += dp[k + 1] * (k + 2) * v[k + 2];
    dp[k] = (sa + s) / (k + c[k + 2]);
  }
  UL(dp[a[K]]);
}
#include "MeIoN_Lib/Z_H/main.hpp"