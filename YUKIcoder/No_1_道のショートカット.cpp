#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, C, m);
  VEC(ll, s, m);
  VEC(ll, t, m);
  VEC(ll, c, m);
  VEC(ll, w, m);
  vector<vector<T3<ll>>> v(n);
  FOR(i, m) {
    --s[i], --t[i];
    v[s[i]].emplace_back(t[i], c[i], w[i]);
  }

  vector dis(n, vector(C + 1, inf<ll>));
  min_heap<T3<ll>> q;
  q.emplace(0, 0, 0);
  dis[0][0] = 0;
  while (not q.empty()) {
    meion [nw, n, nc] = pop(q);
    for (meion [x, cc, ww] : v[n]) {
      ll tw = nw + ww, tc = nc + cc;
      if (tc < C + 1 and chmin(dis[x][tc], tw)) {
        q.emplace(tw, x, tc);
      }
    }
  }
  ll ans = inf<ll>;
  FOR(i, C + 1) chmin(ans, dis[n - 1][i]);
  UL(ans == inf<ll> ? -1 : ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"