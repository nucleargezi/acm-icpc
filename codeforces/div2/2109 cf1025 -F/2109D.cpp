#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/graph/Apck/bfs1.hpp"

#define tests
void Yorisou() {
  LL(n, m, sz);
  VEC(ll, a, sz);
  VEC(PII, e, m);
  ll s = SUM(a);
  ll O = 0, E = 0;
  (s & 1 ? O : E) = s;
  for (ll x : a) {
    if (x & 1) chmax((s & 1 ? E : O), s - x);
  }
  graph g(n << 1);
  for (meion [x, y] : e) {
    --x, --y;
    g.add(x, y + n);
    g.add(y, x + n);
  }
  g.build();
  meion dis = bfs1(g, 0).first;
  string ans(n, '0');
  FOR(i, n) {
    if (O >= dis[i + n] or E >= dis[i]) ans[i]++;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"