#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = long double;
using T = retsu<RE>;
void Yorisou() {
  INT(N, M);
  T dp(N + M + 1, N + M + 1);
  FOR(i, N + M + 1) dp[i][0] = 1, dp[0][i] = 1.l / (i + 1);
  FOR(s, 2, N + M + 1) {
    FOR(i, 1, s) {
      int k = s - i;
      RE a = 1.l, b = 1 - dp[k][i - 1], c = (1 - dp[k - 1][i]) * k / (k + 1),
         d = c + 1.l / (k + 1), p = (d - c) / (a - b - c + d);
      dp[i][k] = a * p + c * (1 - p);
    }
  }
  setp(16);
  print(dp[N][M], 1 - dp[N][M]);
}
#include "YRS/Z_H/main.hpp"