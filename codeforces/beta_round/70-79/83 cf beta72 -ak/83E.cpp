#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(string, s, N);
  FOR(i, N) for (char &c : s[i]) c -= '0';
  const int M = len(s[0]);
  vector<ll> dp(1 << (M + 1), inf<ll> / 4);
  dp[1] = 0;
  ll ad = M;
  FOR(i, 1, N) {
    ll cc = 0;
    FOR(k, M + 1)
      if (s[i - 1].substr(M - k, k) == s[i].substr(0, k)) cc = k;
    int p = 1;
    ll f = inf<ll> / 4;
    FOR(k, M + 1) {
      chmin(f, M - k + dp[p] + ad);
      if (k != M) p = p << 1 | s[i][k];
    }
    ad += M - cc;
    p = 0;
    for (char c : s[i - 1]) p = p << 1 | c;
    FOR(k, M + 1) {
      int id = p & ((1 << k) - 1);
      id |= 1 << k;
      chmin(dp[id], f - ad);
    }
  }
  print(QMIN(dp) + ad);
}
#include "YRS/Z_H/main.hpp"