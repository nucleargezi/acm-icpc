#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  vc<int> a(N + 1);
  FOR(i, 1, N + 1) IN(a[i]);
  FOR(i, N + 1) if (a[i] == -1) a[i] = -inf<int> / 2;
  STR(s);

  retsu<array<int, 151>> dp(N + 1, N + 1);
  FOR(i, N + 1) FOR(k, N + 1) dp[i][k].fill(-inf<int> / 2);
  FOR_R(l, N + 1) FOR(r, l, N + 1) {
    if (l == r) {
      dp[l][r][0] = 0;
      continue;
    }
    if (l + 1 == r) {
      dp[l][r][0] = a[1];
      dp[l][r][1] = 0;
      continue;
    }
    FOR(m, l + 1, r + 1) FOR(i, N + 1) {
      chmax(dp[l][r][i], dp[l][m][0] + dp[m][r][i]);
    }
    FOR(m, l, r) FOR(i, N + 1) {
      chmax(dp[l][r][i], dp[l][m][i] + dp[m][r][0]);
    }
    if (s[l] == s[r - 1]) {
      FOR(i, N - 1) chmax(dp[l][r][i + 2], dp[l + 1][r - 1][i]);
    }
    FOR(i, N + 1) chmax(dp[l][r][0], dp[l][r][i] + a[i]);
  }
  vc<int> f(N + 1, -inf<int> / 2);
  f[0] = 0;
  FOR(i, N) {
    chmax(f[i + 1], f[i]);
    FOR(k, i + 1, N + 1) chmax(f[k], f[i] + dp[i][k][0]);
  }
  print(f[N]);
}

int main() {
  Yorisou();
  return 0;
}