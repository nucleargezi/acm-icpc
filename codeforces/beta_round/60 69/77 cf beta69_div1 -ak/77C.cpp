#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Tree/Basic.hpp"

// #define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  graph g(N);
  g.read_tree();
  INT(rt);
  --rt;
 
  vector<PLL> dp(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    vector<ll> t;
    ll s = 0, ch = 0;
    for (Z &&e : g[n]) {
      int to = e.to;
      if (to == fa) continue;
      ++ch;
      f(f, to, n);
      s += dp[to].se;
      t.ep(dp[to].fi);
    }
    if (ch == 0) return dp[n] = {0, a[n] - (n != rt)}, void();
    sort(t, greater());
    ll ad = 0, ls = a[n] - (n != rt);
    for (ll x : t) if (ls) ad += x + 2, --ls;
    ad += std::min(ls, s) << 1;
    ls -= std::min(ls, s);
    dp[n] = {ad, ls};
  };
  f(f, rt, -1);
  print(dp[rt].fi);
}
#include "YRS/Z_H/main.hpp"