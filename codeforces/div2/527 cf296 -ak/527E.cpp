#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  graph g(n);
  graph<int, 1> v(n);
  vector<vector<PLL>> ng(n);
  ll t = 0;
  FOR(m) {
    LL(x, y);
    --x, --y;
    g.add(x, y);
    v.add(x, y);
    v.add(y, x);
    ng[x] += PLL{y, t};
    ng[y] += PLL{x, t};
    ++t;
  }
  g.build();
  meion [in, ou] = g.deg_array_inout();
  vector<ll> ps;
  FOR(i, n) if (in[i] + ou[i] & 1) ps += i;
  if (len(ps) & 1) ps += ps[0];
  FOR(i, 0, len(ps), 2) {
    ll x = ps[i], y = ps[i + 1];
    v.add(x, y);
    v.add(y, x);
    ng[x] += PLL(y, t);
    ng[y] += PLL(x, t);
    ++t;
  }
  v.build();
  meion [cnt, id] = scc(v);
  vector<ll> c(cnt), ch(cnt);
  for (meion &&e : v.edges) {
    assert(id[e.f] == id[e.to]);
    ++c[id[e.f]];
    ch[id[e.f]] = e.f;
  }
  FOR(i, cnt) {
    if (c[i] >> 1 & 1) {
      FOR(2) ng[ch[i]] += PLL{ch[i], t};
      ++t;
    }
  }
  vector<ll> tp(n), path;
  vector<u8> vis(t);
  meion f = [&](meion &f, ll n) -> void {
    for (ll i = 0; i < len(ng[n]); i = MAX(i + 1, tp[n])) {
      meion [x, id] = ng[n][i];
      if (vis[id]) continue;
      vis[id] = 1;
      tp[n] = i + 1;
      f(f, x);
    }
    path += n + 1;
  };
  f(f, 0);
  UL(len(path) - 1);
  FOR(i, 1, len(path)) {
    if (i & 1)
      UL(path[i - 1], path[i]);
    else
      UL(path[i], path[i - 1]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"