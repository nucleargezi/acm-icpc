#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, q);
  VEC(T3<ll>, e, m);
  for (meion &[x, y, _] : e) --x, --y;
  vector dp(32, vector(n, -inf<ll>));
  FOR(i, 32) {
    for (meion &[x, y, w] : e) {
      chmax(dp[i][x], i ? dp[i - 1][y] * w : w);
      chmin(dp[i][x], inf<int>);
    }
  }
  FOR(q) {
    LL(p, w);
    --p;
    UL(binary_search([&](int t) -> bool {
      iroha dp[t][p] > w;
    }, 31, -1) + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"