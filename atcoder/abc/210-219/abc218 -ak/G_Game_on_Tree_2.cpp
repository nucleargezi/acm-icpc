#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/heap/heap_minmax.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  vector<vector<int>> v(n);
  FOR(n - 1) {
    LL(x, y);
    --x, --y;
    v[x] += y;
    v[y] += x;
  }
  vector<int> dp(n), dis(n);
  heap_minmax<int> q;
  meion f = [&](meion &f, int n, int fa = 0) -> void {
    q.push(a[n]);
    ll mx = 0, mn = inf<int>;
    for (ll x : v[n]) {
      if (x == fa) continue;
      dis[x] = dis[n] + 1;
      f(f, x, n);
      chmin(mn, dp[x]), chmax(mx, dp[x]);
    }
    if (mn == inf<int>) {
      meion [a, b] = q.get();
      dp[n] = a + b >> 1;
    } else {
      dp[n] = (dis[n] & 1) ? mn : mx;
    }
    q.pop(a[n]);
  };
  f(f, 0);
  UL(dp[0]);
}
#include "MeIoN_Lib/Z_H/main.hpp"