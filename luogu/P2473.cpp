#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = double;
void Yorisou() {
  INT(K, N);
  vector<PII> a(N);
  FOR(i, N) {
    INT(x);
    a[i].fi = x;
    while (IN(x) and x) --x, a[i].se |= 1 << x;
  }
  int sz = 1 << N;
  vc<RE> dp(sz), ndp(sz);
  FOR(K) {
    FOR(s, sz) {
      ndp[s] = 0;
      FOR(i, N) {
        RE mx = dp[s];
        if (a[i].se == (a[i].se & s)) chmax(mx, a[i].fi + dp[1 << i | s]);
        ndp[s] += mx;
      }
      ndp[s] /= N;
    }
    dp.swap(ndp);
  }
  setp(6);
  print(dp[0]);
}
#include "YRS/Z_H/main.hpp"