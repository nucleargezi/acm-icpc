#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  retsu<int> dp(1 << N, 1000, inf<int>);
  dp[0][0] = 0;
  FOR(s, 1 << N) FOR(k, 1000) if (dp[s][k] != inf<int>) {
    FOR(i, N) if ((s >> i & 1) == 0) {
      chmin(dp[1 << i | s][(k + a[i]) % 1000], dp[s][k] + max(0, a[i] - k));
    }
  }
  int s = inf<int>;
  FOR(i, 1000) chmin(s, dp[(1 << N) - 1][i]);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"