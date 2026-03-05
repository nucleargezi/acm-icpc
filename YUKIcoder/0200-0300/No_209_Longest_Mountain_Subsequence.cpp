#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f = [&]() {
    retsu<int> dp(N, N);
    FOR(i, N) {
      FOR(k, i) FOR(j, k + 1) {
        if (dp[k][j] and a[i] > a[k] and a[i] - a[k] > a[k] - a[j]) {
          chmax(dp[i][k], dp[k][j] + 1);
        }
      }
      dp[i][i] = 1;
    }
    return dp;
  };
  Z L = f();
  reverse(a);
  Z R = f();
  FOR(i, N) FOR(k, i) swap(R[i][k], R[N - i - 1][N - k - 1]);
  int s = 1;
  FOR(i, N) FOR(l, i + 1) FOR(r, i, N) {
    chmax(s, L[i][l] + R[i][r] - 1);
  }
  print(s);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"