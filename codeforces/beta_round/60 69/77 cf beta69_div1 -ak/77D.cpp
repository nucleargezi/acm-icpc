#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using A = retsu<int>;
using mint = M17;
void Yorisou() {
  INT(N, M);
  VEC(string, s, N << 2 | 1);
  A a(N, M);

  vector<int> dl{0, 16, 68, 84, 325, 341, 365},
              dr{0, 16, 257, 273, 325, 341, 455};
  FOR(i, N) FOR(k, M) {
    string t;
    FOR(j, 1, 4) t += s[i << 2 | j].substr(k << 2 | 1, 3);
    int s = 0;
    FOR(i, 9) if (t[i] == 'O') s |= 1 << i;
    FOR(j, 7) if (s == dl[j]) a[i][k] |= 1;
    FOR(j, 7) if (s == dr[j]) a[i][k] |= 2;
  }

  vector<mint> dp(M + 1);
  dp[0] = 1;
  Z f = [&](int k) -> mint {
    if (N & 1) return 0;
    FOR(i, N) if (a[i][k] == 2) return 0;
    return 1;
  };
  Z ff = [&](int k) -> mint {
    retsu<mint> dp(2, N + 1);
    dp[0][0] = 1;
    FOR(i, N) {
      if (a[i][k] != 1 and a[i][k + 1] != 1) {
        dp[1][i + 1] += dp[0][i] + dp[1][i];
      }
      if (i + 1 < N) {
        bool f = true;
        FOR(j, 2) FOR(l, 2) f &= a[i + j][k + l] != 2;
        if (f) dp[0][i + 2] += dp[0][i], dp[1][i + 2] += dp[1][i];
      }
    }
    return dp[1][N];
  };
  FOR(k, M) {
    dp[k + 1] += dp[k] * f(k);
    if (k + 2 <= M) dp[k + 2] += dp[k] * ff(k);
  }
  print(dp[M]);
}
#include "YRS/Z_H/main.hpp"