#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/sl/lict_d.hpp"

using DS = lict_d<ll, 1, 1, int>;
using np = DS::np;
void Yorisou() {
  INT(N);
  vc<vc<PII>> g(N);
  FOR(N - 1) {
    INT(f, t, w);
    --f, --t;
    g[f].ep(t, w);
    g[t].ep(f, w);
  }
  vc<PII> dat(N);
  FOR(i, 1, N) IN(dat[i]);

  vc<ll> dis(N);
  vc<np> t(N, 0);
  DS seg(0, 1'000'000'001);
  vc<ll> dp(N);
  Z f = [&](Z &f, int n, int p) -> void {
    if (n != 0) {
      var [w, v] = dat[n];
      dp[n] = seg.get(t[n], v).fi + dis[n] * v + w;
    }
    t[n] = seg.add(t[n], {-dis[n], dp[n]});
    for (var [x, w] : g[n]) if (x != p) {
      t[x] = t[n];
      dis[x] = dis[n] + w;
      f(f, x, n);
    }
  };
  f(f, 0, -1);
  dp.erase(bg(dp));
  print(dp);
}

int main() {
  Yorisou();
  return 0;
}