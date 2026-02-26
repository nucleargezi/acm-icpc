#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vc<int> T(N), B(N);
  FOR(i, N) IN(T[i], B[i]);
  vc<array<array<int, 17>, 1 << 8>> dp(N + 1);
  FOR(i, N + 1) FOR(k, 1 << 8) dp[i][k].fill(inf<int> / 2);
  dp[0][0][7] = 0;
  FOR(i, N) {
    FOR(s, 1 << 8) {
      FOR(k, -8, 8) {
        if (dp[i][s][k + 8] != inf<int> / 2) {
          if (s & 1) chmin(dp[i + 1][s >> 1][k + 7], dp[i][s][k + 8]);
          else {
            int in = inf<int> / 2;
            FOR(j, 8) if (~s >> j & 1) if (i + j < N and i + j <= in) {
              chmin(in, i + j + B[i + j]);
              chmin(dp[i][1 << j | s][j + 8],
                  dp[i][s][k + 8] + (i + k >= 0 ? (T[i + k] ^ T[i + j]) : 0));
            }
          }
        }
      }
    }
  }
  int s = inf<int> / 2;
  FOR(k, 9) chmin(s, dp[N][0][k]);
  print(s);
}
#include "YRS/aa/main.hpp"