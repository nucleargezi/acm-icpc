#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"

// #define tests
void Yorisou() {
  STR(s);
  INT(K, M);
  static int c[30][30];
  FOR(M) {
    CH(a, b);
    INT(w);
    c[a - 'a'][b - 'a'] = w;
  }
  for (Z &c : s) c -= 'a';
  const int N = len(s);
  retsu<int> dp(K + 1, 26, -inf<int>), ndp(dp);
  FOR(i, 26) {
    if (i == s[0]) dp[0][i] = 0;
    else if (K) dp[1][i] = 0;
  }
  FOR(i, 1, N) {
    ndp.fill(-inf<int>);
    FOR(x, K + 1) FOR(f, 26) if (dp[x][f] != -inf<int>) FOR(t, 26) {
      if (s[i] == t) {
        chmax(ndp[x][t], dp[x][f] + c[f][t]); 
      } else if (x < K) {
        chmax(ndp[x + 1][t], dp[x][f] + c[f][t]);
      }
    }
    swap(dp, ndp);
  }
  print(QMAX(dp.A));
}
#include "YRS/Z_H/main.hpp"