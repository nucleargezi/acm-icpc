#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mat.hpp"

void before() {}

// #define tests
constexpr int N = 100;
using mint = M17;
using M = MAT<mint, N + 1>;
void Yorisou() {
  LL(n, x);
  M m;
  m[0][0] = m[0][N] = 1;
  FOR(i, 1, N) m[i + 1][i] += 1;
  FOR(i, n) {
    LL(x);
    m[N - x + 1][N] += 1;
  }
  vector<mint> dp(N);
  FOR(i, N) {
    dp[i] = 1;
    FOR(k, 1, N + 1) {
      if (i - (N - k + 1) > -1) {
        dp[i] += m[k][N] * dp[i - (N - k + 1)];
      }
    }
  }
  dp.insert(dp.begin(), 1);
  mint ans;
  m = m.ksm(x);
  FOR(i, N + 1) ans += dp[i] * m[i][1];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"