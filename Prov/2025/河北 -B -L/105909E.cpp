#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

// #define tests
using mint = M17;
using RE = long double;
constexpr mint in = mint(100).inv();
void Yorisou() {
  LL(n, h, K);
  mint x;
  IN(x);
  RE px = x.val / 100.L;
  x *= in;
  VEC(mint, q, n);
  VEC(mint, p, n);
  vector<RE> cp(n);
  FOR(i, n) cp[i] = p[i].val / 100.L;
  FOR(i, n) q[i] *= in;
  FOR(i, n) p[i] *= in;

  static constexpr ll N = 500;
  vector pwt = power_table_1<mint>(x, N);
  vector<mint> dp(N);
  dp[0] = 1;
  FOR(i, n) {
    vector<mint> ndp(N);
    RE pp = cp[i];
    FOR(k, MIN(N, h)) {
      if (pp >= 1) break;
      mint cp = p[i] * pwt[k];
      ndp[k] += (-cp + 1) * (-q[i] + 1) * dp[k];
      if (k + 1 < h) ndp[k + 1] += (-cp + 1) * q[i] * dp[k];
      pp *= px;
    }
    dp.swap(ndp);
    if (K and (i + 1) % K == 0) {
      dp[0] = SUM<mint>(dp);
      FOR(i, 1, N) dp[i] = 0;
    }
  }
  UL(SUM<mint>(dp).inv());
}
#include "MeIoN_Lib/Z_H/main.hpp"