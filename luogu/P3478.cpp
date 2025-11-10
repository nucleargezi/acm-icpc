#define D
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/graph/Tree/dp/rerooting_tree_dp.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  using X = pair<ll, int>;
  Z fee = [&](X x, X y) -> X { return {x.fi + y.fi, x.se + y.se}; };
  Z fev = [&](X x, int i) -> X { return x; };
  Z fve = [&](X x, Z e) -> X { return {x.fi + x.se, x.se}; };
  rerooting_tree_dp<decltype(v), X> dp(v, fee, fev, fve, {0, 1});
  ll mx = -1, ans = -1;
  FOR(i, N) if (chmax(mx, dp[i].fi)) ans = i + 1;
  print(ans);
}
#include "YRS/Z_H/main.hpp"