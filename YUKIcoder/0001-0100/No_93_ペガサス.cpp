#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(N);
  vc<mint> dp[4];
  FOR(i, 4) dp[i].resize(N, 0);
  dp[0][0] = 1;
  FOR(i, 1, N) {
    fill(all(dp[2]), 0);
    fill(all(dp[3]), 0);
    if (i != ceil(N, 2)) FOR(k, N) dp[3][k] += dp[0][k] + dp[1][k];
    FOR(k, N - 1) dp[2][k + 1] += dp[0][k] + dp[1][k] * 2;
    dp[0].swap(dp[2]);
    dp[1].swap(dp[3]);
  }
  FOR(i, N) dp[0][i] += dp[1][i] * 2;
  mint s = 0;
  FOR(i, N) {
    s += dp[0][i] * fac(i + 1) * ((N - i) & 1 ? 1 : -1);
  }
  print(s);
}
#include "YRS/aa/main.hpp"