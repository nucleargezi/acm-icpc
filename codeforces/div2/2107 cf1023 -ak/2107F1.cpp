#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  lichao_tree<Line<ll>, 0, 1> seg(0, n, Line<ll>(0, inf<ll>));
  vector<PLL> s;
  FOR(i, n) {
    while (not s.empty() and a[s.back().first] > a[i]) s.pop_back();
    if (s.empty()) {
      s += PLL(i, (a[i] + 1) * (i + 1) - 1);
    } else {
      meion [idx, cost] = s.back();
      cost += (a[i] + 1) * (i - idx) - 1;
      s += PLL(i, cost);
    }
    seg.chmin_line(Line<ll>(a[i] + 2, s.back().second - (a[i] + 2) * i));
  }
  UL(seg.query(n - 1).first);
}
#include "MeIoN_Lib/Z_H/main.hpp"