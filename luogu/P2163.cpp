#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(PLL, ps, n);
  sort(ps);
  constexpr int INF = inf<int> >> 1;
  ps += PLL(INF, INF);
  vector<ll> a(n + 1);
  FOR(i, n + 1) a[i] = ps[i].second;
  Wavelet_Matrix seg(a);
  FOR(q) {
    LL(l, d, r, u);
    l = lower_bound(ps, PLL(l, -INF));
    r = upper_bound(ps, PLL(r + 1, -INF));
    UL(seg.count(l, r, d, u + 1));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"