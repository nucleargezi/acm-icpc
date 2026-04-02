#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M17;
void Yorisou() {
  INT(N, K);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(x, y);
    g[x].ep(y);
    g[y].ep(x);
  }
  vc<vc<mint>> dp(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    dp[n].ep(mint(1));
    for (int x : g[n]) if (x != fa) {
      f(f, x, n);
      int N = len(dp[x]), M = len(dp[n]);
      sh(dp[n], N + M - 1);
      FOR_R(k, M) FOR(i, 1, N) if (dp[n][k].val() != 0) dp[n][k + i] += dp[n][k] * dp[x][i];
    }
    dp[n].ep(mint(1));
  };
  f(f, 0, -1);
  print(dp[0][K]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"