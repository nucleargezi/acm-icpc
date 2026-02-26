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
  VEC(int, a, N);
  INT(M);
  VEC(int, b, M);
  sort(b, greater());
  if (M > N) sh(b, N), M = N;
  int ans = inf<int>;
  bitset<1 << 10> dp[11]{};
  dp[0][0] = 1;
  FOR(m, M) FOR(s, 1 << N) if (dp[m][s]) {
    int wt = ((1 << N) - 1) ^ s;
    FOR_subset(t, wt) {
      int c = 0;
      FOR(k, N) if (t >> k & 1) c += a[k];
      if (c > b[m]) continue;
      dp[m + 1][s | t] = 1;
    }
  }
  FOR(m, 1, M + 1) if (dp[m][(1 << N) - 1]) chmin(ans, m);
  print(ans == inf<int> ? -1 : ans);
}
#include "YRS/aa/main.hpp"