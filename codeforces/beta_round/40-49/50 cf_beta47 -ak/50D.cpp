#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  LL(n, K);
  REA(P);
  P /= 1000;
  LL(x0, y0);
  VEC(PLL, p, n);
  constexpr RE eps = 1e-8L;
  UL(binary_search_real([&](RE R) {
    vector<RE> dp(n + 1), ndp(n + 1);
    dp[0] = 1;
    FOR(i, n) {
      fill(ndp, 0);
      meion [x, y] = p[i];
      x -= x0, y -= y0;
      RE d = std::sqrt(x * x + y * y);
      RE p = R + eps >= d ? 1 : std::exp(1.L - RE(x * x + y * y) / R / R);
      FOR(k, n) if (dp[k]) {
        ndp[k + 1] += dp[k] * p;
        ndp[k] += dp[k] * (1.L - p);
      }
      dp.swap(ndp);
    }
    RE s = 0;
    FOR(i, K, n + 1) s += dp[i];
    iroha s >= 1 - P;
  }, 1'000001, 0));
}
#include "MeIoN_Lib/Z_H/main.hpp"