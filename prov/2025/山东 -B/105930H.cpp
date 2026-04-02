#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

#define tests
void Yorisou() {
  LL(n, m, K);
  VEC(T3<ll>, e, m);
  ll ans = 0;
  dsu g(n);
  for (meion &[x, y, w] : e) {
    --x, --y;
    std::swap(x, w);
  }
  meion I = argsort(e);
  vector<int> mst;
  FOR(i, m) {
    meion [w, x, y] = e[I[i]];
    if (g.merge(x, y)) {
      mst += I[i];
      ans += w;
    }
  }
  reverse(mst);
  int L = 0;
  FOR(i, MIN(n - 1, K)) {
    if (1 - std::get<0>(e[mst[i]]) >= 0) break;
    L = i + 1;
    ans += 1 - std::get<0>(e[mst[i]]);
  }
  g.reset();
  FOR(i, L, n - 1) {
    meion [w, x, y] = e[mst[i]];
    g.merge(x, y);
  }
  vector<PLL> ad;
  FOR(i, n - 1) {
    if (g.merge(i, i + 1)) ad.emplace_back(i + 1, i + 2);
  }
  UL(len(ad));
  FOR(i, len(ad)) UL(ad[i]);
  UL(ans);
  vector<int> chs;
  FOR(i, L, n - 1) chs += mst[i] + 1;
  FOR(i, len(ad)) chs += m + i + 1;
  UL(chs);
}
#include "MeIoN_Lib/Z_H/main.hpp"