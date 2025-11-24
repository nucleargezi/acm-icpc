#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
bool ok(int x) {
  while (x) {
    int t = x % 10;
    if (t != 7 and t != 4) return 0;
    x /= 10;
  }
  return 1;
}
void Yorisou() {
  INT(N, M);
  dsu g(N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    g.merge(x, y);
  }
  vc<int> a(N + 1), dp(N + 1, inf<int>);
  dp[0] = 0;
  FOR(i, N) if (g[i] == i) a[g.size(i)] += 1;
  FOR(i, 1, N + 1) if (a[i]) {
    int c = a[i], sz = i, k = 1, re = c;
    while (re > 0) {
      int cc = min(k, re), w = cc * sz;
      FOR_R(i, N - w + 1) 
        if (dp[i] != inf<int>) chmin(dp[i + w], dp[i] + cc);
      re -= cc, k <<= 1;
    }
  }
  int ans = inf<int>;
  FOR(i, 1, N + 1) if (ok(i) and dp[i] != inf<int>) chmin(ans, dp[i] - 1);
  print(ans == inf<int> ? -1 : ans);
}
#include "YRS/Z_H/main.hpp"