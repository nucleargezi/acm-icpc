#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  vector<vector<pair<int, mint>>> v(m + 1);
  mint x = 1;
  FOR(n) {
    LL(l, r, p, q);
    --l;
    mint d = q - p;
    x *= d / q;
    v[r].emplace_back(l, mint(p) / d);
  }
  vector<mint> dp(m + 1);
  dp[0] = 1;
  FOR(i, 1, m + 1) {
    for (meion [x, y] : v[i]) {
      dp[i] += dp[x] * y;
    }
  }
  UL(dp[m] * x);
}
#include "MeIoN_Lib/Z_H/main.hpp"