#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vvc<int> g(N);
  FOR(N - 1) {
    INT(x, y);
    --x, --y;
    g[x].ep(y);
    g[y].ep(x);
  }

  vc<int> V, sz(N), fa(N, -1);
  Z f = [&](Z &f, int n) -> void {
    V.ep(n);
    for (int x : g[n]) if (x != fa[n]) {
      ++sz[n];
      fa[x] = n;
      f(f, x);
    }
  };
  f(f, 0);
  vc<int> dp(N);
  print(bina([&](int k) -> bool {
    FOR_R(i, N) {
      int x = V[i];
      dp[x] = k - sz[x];
      for (int t : g[x]) if (t != fa[x]) {
        dp[x] += min(dp[t], 0);
      }
    }
    return dp[0] >= 0;
  }, N, 0));
}
#include "YRS/aa/main.hpp"