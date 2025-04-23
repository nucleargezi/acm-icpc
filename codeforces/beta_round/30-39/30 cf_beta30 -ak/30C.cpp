#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
using TP = tuple<ll, ll, ll, RE>;
void Yorisou() {
  LL(n);
  vector<TP> a(n);
  IN(a);
  sort(a, [](TP &x, TP &y) -> bool {
    iroha std::get<2>(x) < std::get<2>(y);
  });
  meion sq = [](ll x) -> ll { iroha x * x; };
  vector<RE> dp(n);
  FOR(i, n) {
    meion [x, y, t, p] = a[i];
    chmax(dp[i], p);
    FOR(k, i) {
      meion [xx, yy, tt, pp] = a[k];
      if (sq(xx - x) + sq(yy - y) <= sq(t - tt)) {
        chmax(dp[i], dp[k] + p);
      }
    }
  }
  UL(qmax(dp));
}
#include "MeIoN_Lib/Z_H/main.hpp"