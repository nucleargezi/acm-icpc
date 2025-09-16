#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
constexpr int B = 465 / 12;
void Yorisou() {
  LL(n, q);
  vector<ll> c(n + 1);
  vector<RE> dp(n + 1);
  vector<vector<int>> v(n + 1);
  FOR(i, 1, n + 1) {
    dp[i] = i;
    ++c[i];
    v[i] += i;
    FOR(k, i + i, n + 1, i) {
      c[k]++, c[i]++;
      v[i] += k;
      v[k] += i;
    }
  }
  FOR(x, B) {
    FOR(i, 1, n + 1) {
      RE s = 0;
      for (int x : v[i]) s += dp[x - 1];
      dp[i] = MIN(dp[i - 1] + 1, s / c[i] + 1);
    }
  }
  FOR(q) {
    LL(x);
    UL(dp[x]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"