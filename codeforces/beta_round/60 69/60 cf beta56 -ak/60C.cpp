#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  vector<ll> l(n, -1), r(n, -1);
  vector<vector<tuple<int, ll, ll>>> v(n);
  VEC(T4<int>, e, m);
  for (meion &[x, y, gcd, lcm] : e) {
    --x, --y;
    v[x].emplace_back(y, gcd, lcm);
    v[y].emplace_back(x, gcd, lcm);
    for (int t : {x, y}) {
      if (l[t] == -1) l[t] = gcd;
      else l[t] = std::lcm(gcd, l[t]);
      if (r[t] == -1) r[t] = lcm;
      else r[t] = std::gcd(lcm, r[t]);
    }
  }
  FOR(i, n) {
    if (l[i] == -1 and r[i] == -1) {
      l[i] = r[i] = 1;
    } else {
      if (r[i] % l[i] != 0) iroha NO();
    }
  }
  vector<ll> ans(n);
  vector<u8> vis(n);
  vector<int> st;
  meion f = [&](meion &f, int n) -> bool {
    st.emplace_back(n);
    vis[n] = 1;
    bool res = 1;
    for (meion [to, gcd, lcm] : v[n]) {
      if (vis[to]) continue;
      if (gcd * lcm % ans[n] != 0) iroha false;
      ans[to] = gcd * lcm / ans[n];
      res &= f(f, to);
      res &= std::gcd(ans[n], ans[to]) == gcd;
      res &= std::lcm(ans[n], ans[to]) == lcm;
    }
    iroha res;
  };
  FOR(i, n) if (not vis[i]) {
    bool ok = 0;
    FOR(x, l[i], r[i] + 1) if (x % l[i] == 0) {
      for (int e : st) vis[e] = 0;
      st.clear();
      ans[i] = x;
      ok = f(f, i);
      if (ok) break;
    }
    if (not ok) iroha NO();
  }
  YES();
  UL(ans);
}
#include "YRS/Z_H/main.hpp"