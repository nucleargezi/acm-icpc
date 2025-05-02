#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<u8> vis(n);
  set<PLL> se, q;
  FOR(i, n) se += PLL{-a[i], i};
  ll ans = 0;
  meion ext = [&](ll id) {
    vis[id] = 1;
    se -= PLL(-a[id], id);
    FOR(x, id - 1, id + 2)
      if (x > -1 and x < n and not vis[x]) 
        q += PLL{-a[x], x};
  };
  while (not se.empty()) {
    meion [w, id] = *se.begin();
    ext(id);
    ++ans;
    while (not q.empty() and q.begin()->first <= se.begin()->first) {
      meion x = *q.begin();
      q -= x;
      ext(x.second);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"