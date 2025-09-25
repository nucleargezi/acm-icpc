#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/ds/basic/retsu.hpp"

// #define tests
using mint = M17;
using A = retsu<mint>;
int N, M;
void yorisou() {
  vector<int> L(N, -1);
  FOR(M) {
    INT(l, r);
    --l, --r;
    chmax(L[r], l);
  }
  A dp(N + 1, N + 1), ndp(N + 1, N + 1);
  dp[0][0] = 1;
  FOR(i, N) {
    ndp.fill(0);
    FOR(k, i + 1) FOR(j, k, i + 1) if (dp[k][j] != 0) {
      if (k > L[i]) ndp[k][j] += dp[k][j] * 6;
      if (j > L[i]) ndp[j][i + 1] += dp[k][j] * 2;
      ndp[i + 1][i + 1] += dp[k][j] * 2;
    }
    swap(dp, ndp);
  }
  mint ans;
  FOR(i, N + 1) FOR(k, N + 1) ans += dp[i][k];
  print(ans);
}
void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"