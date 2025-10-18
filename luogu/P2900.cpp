#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  sort(a, greater());
  vector<PLL> b;
  for (meion [x, y] : a) {
    if (b.empty() or y > b.back().second) {
      b += PLL(x, y);
    }
  }
  n = len(b);
  lichao_tree<Line<ll>, 0, 1> seg(0, b[n - 1].second + 1, Line<ll>(0, inf<ll>));
  vector<ll> dp(n);
  FOR(i, n) {
    meion [x, y] = b[i];
    seg.chmin_line(Line<ll>(x, i ? dp[i - 1] : 0));
    dp[i] = seg.query(y).first;
  }
  UL(dp[n - 1]);
}
#include "MeIoN_Lib/Z_H/main.hpp"