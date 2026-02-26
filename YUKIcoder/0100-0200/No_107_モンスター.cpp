#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  int N, M;
  IN(N);
  vc<int> a, b;
  FOR(N) {
    INT(x);
    (x < 0 ? a : b).ep(abs(x));
  }
  sort(a);
  sort(b);
  N = len(a);
  M = len(b);
  retsu<int> dp(1 << N, 1 << M);
  dp[0][0] = 100;
  FOR(s, 1 << N) FOR(h, 1 << M) if (dp[s][h]) {
    FOR(i, N) if ((s >> i & 1) == 0) {
      if (dp[s][h] > a[i]) chmax(dp[1 << i | s][h], dp[s][h] - a[i]);
    }
    FOR(i, M) if ((h >> i & 1) == 0) {
      chmax(dp[s][1 << i | h], min(dp[s][h] + b[i], 100 + pc(s) * 100));
    }
  }
  int s = 0;
  FOR(i, 1 << M) chmax(s, dp[(1 << N) - 1][i]);
  print(s);
}
#include "YRS/aa/main.hpp"