#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/string/run_length.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(N);
  vector<vector<int>> v(N);
  vector<pair<ll, mint>> dp(N); 
  FOR(i, 1, N) {
    INT(x);
    --x;
    v[x].ep(i);
  }
  ll ans = N;
  Z f = [&](Z &f, int n) -> void {
    dp[n] = {1, 1};
    vector<ll> c;
    for (int x : v[n]) {
      f(f, x);
      c.ep(dp[x].fi);
      dp[n].se *= dp[x].se;
    }
    sort(c);
    for (ll s = 0; ll x : c) {
      s += x;
      ans += s;
    }
    for (Z [e, p] : run_length(c)) {
      dp[n].fi += e * p;
      dp[n].se *= fact<mint>(p);
    }
  };
  f(f, 0);
  print(ans);
  print(dp[0].se);
}
#include "YRS/Z_H/main.hpp"