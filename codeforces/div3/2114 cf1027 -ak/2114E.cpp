#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  graph g(n);
  g.read_tree();
  vector<ll> dp(n + 1, -inf<ll>);
  vector<ll> ans(n);
  dp[n] = 0;
  meion f = [&](meion &f, int n, int fa, bool ad) -> void {
    dp[n] = MAX(dp[fa], 0ll) + (ad ? a[n] : -a[n]);
    if (ad) ans[n] = dp[n];
    for (meion &&e : g[n]) {
      if (e.to == fa) continue;
      f(f, e.to, n, not ad);
    }
  };
  f(f, 0, n, 1);
  f(f, 0, n, 0);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"