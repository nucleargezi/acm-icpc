#include "YRS/all.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  using ll = bigint;
  INT(N);
  graph g(N);
  g.sc();
  
  vc<int> sz(N);
  vc<ll> vl(N);
  Z f = [&](Z &f, int n, int fa) -> vc<ll> {
    vc<ll> dp(2);
    dp[1] = 1;
    int s = 1;
    for (Z &&e : g[n]) if (e.to != fa) {
      vc<ll> cdp = f(f, e.to, n), ndp(sz[e.to] + s + 1);
      int cs = sz[e.to];
      FOR(i, 1, s + 1) if (not dp[i].is_zero()) {
        chmax(ndp[i], dp[i] * vl[e.to]);
        FOR(k, 1, cs + 1) if (not cdp[k].is_zero()) {
          chmax(ndp[i + k], dp[i] * cdp[k]);
        }
      }
      dp.swap(ndp);
      s += cs;
    }
    sz[n] = s;
    ll mx;
    FOR(i, 1, s + 1) if (not dp[i].is_zero()) chmax(mx, dp[i] * i);
    vl[n] = mx;
    return dp;
  };
  f(f, 0, 0);
  print(vl[0]);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"