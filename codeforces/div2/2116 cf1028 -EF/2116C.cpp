#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/gcd_fast.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  ll gcd = 0;
  FOR(i, n) gcd = gcd_fast(gcd, a[i]);
  const int N = QMAX(a) + 1;
  vector<int> dp(N, n), ndp(N, n);
  FOR(i, n) {
    ndp[a[i]] = 0;
    FOR(k, N) if (dp[k] < n) {
      chmin(ndp[gcd_fast(k, a[i])], dp[k] + 1);
    }
    dp = ndp;
  }
  print("{}", dp[gcd] + n - MAX<int>(1, std::ranges::count(a, gcd)));
}
#include "MeIoN_Lib/Z_H/main.hpp"