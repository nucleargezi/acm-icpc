#include "YRS/all.hpp"
#include "YRS/tr/dp/rerooting_tree_dp.hpp"

void Yorisou() {
  INT(N);
  graph g(N);
  g.sc();
  hld v(g);
  vc<u8> vis(N);
  FOR(i, N) if (si(v.cc(i)) == 0) vis[i] = 1;
  Z fee = [&](int x, int y) { return min(x, y); };
  Z fev = [&](int x, int i) { return vis[i] ? 0 : x; };
  Z fve = [&](int x, Z e) { return x + 1; };
  rerooting_tree_dp<int, int> dp(v, fee, fev, fve, inf<int> / 2);
  FOR(i, N) print(min(v.d[i], dp[i]));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"