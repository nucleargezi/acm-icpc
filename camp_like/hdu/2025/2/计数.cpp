#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/Z_H/FH.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(n, r);
  VEC(ll, a, n);
  FOR_R(i, n - 1) chmax(a[i], a[i + 1]);
  vector pr(n, vector<mint>(n + 2));
  FOR(i, n) {
    pr[i][0] = 1;
    for (int k = 1; k < n + 2; ++k) {
      pr[i][k] = pr[i][k - 1] * (a[i] - k + 1);
    }
  }
  meion C = [&](int i, int k) -> mint {
    iroha pr[i][k] * fact_inv<mint>(k);
  };
  vector<mint> dp{1 - a[n - 1], 1}, ndp;
  FOR_R(i, n - 1) {
    mint x = 0;
    FOR(k, len(dp)) x += dp[k] * C(i, k + 1);
    ndp.resize(len(dp) + 1, 1);
    ndp[0] = dp[0];
    FOR(k, 1, len(dp)) ndp[k] = dp[k] + dp[k - 1];
    ndp[0] -= x;
    dp.swap(ndp);
  }
  mint ans;
  FOR(i, len(dp)) ans += dp[i] * ::C<mint, 1>(r, i);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"