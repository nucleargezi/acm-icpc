#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/string/run_length.hpp"

#define tests 1
#define fl 0
#define DB 10
constexpr ll in = -inf<ll>;
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  FOR(i, 1, N) chmax(a[i], a[i - 1]);
  Z g = run_length(a);
  retsu<ll> dp(K + 1, K + 1, in), ndp(K + 1, K + 1), f(K + 1, K + 1);
  dp[0][0] = 0;
  for (Z [x, c] : g) {
    FOR(i, K + 1) FOR(k, K + 1) ndp[i][k] = in;
    FOR(i, K + 1) {
      ll e = in;
      f[i][0] = in;
      FOR(k, 1, K + 1) chmax(e, dp[i][k - 1]), f[i][k] = e;
    }
    FOR(i, K + 1) FOR(k, K + 1) if (dp[i][k] != in) chmax(ndp[i][k], dp[i][k] + c * k);
    FOR(i, K + 1) FOR(k, 1, min(x + 1, K - i + 1)) 
      if (f[i][k] != in) chmax(ndp[i + k][k], f[i][k] + c * k);
    dp.A.swap(ndp.A);
  }
  ll s = 0;
  FOR(i, K + 1) FOR(k, K + 1) chmax(s, dp[i][k]);
  print(s);
}
#include "YRS/Z_H/main.hpp"