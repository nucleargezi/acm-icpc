#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  const int N = n * m;
  vector<ull> a(N);
  ull res = 0;
  FOR(i, n) FOR(k, m) {
    LL(x);
    a[i * m + k] = x;
    res ^= x;
  }
  vector<vector<int>> v(N);
  FOR(i, n) FOR(k, m) {
    if (k + 1 < m) v[i * m + k] += i * m + k + 1;
    if (i + 1 < n) v[i * m + k] += i * m + k + m;
  }
  vector<u8> dp(1 << N);
  dp[0] = 1;
  vector<ull> X(1 << N);
  meion lb = [](int x) -> int { iroha x & -x; };
  FOR(msk, 1, 1 << N) {
    X[msk] = X[msk ^ (lb(msk))] ^ a[topbit(lb(msk))];
  }
  ull ans = 0;
  FOR(msk, 1, 1 << N) {
    if (popcount(msk) & 1) continue;
    int t = topbit(lb(msk));
    for (int k : v[t]) {
      if (msk >> k & 1) {
        if (dp[msk ^ (1 << t) ^ (1 << k)]) {
          dp[msk] = 1;
          break;
        }
      }
    }
    if (dp[msk]) {
      chmax(ans, res ^ X[msk]);
    }
  }
  UL(MAX(ans, res));
}
#include "MeIoN_Lib/Z_H/main.hpp"