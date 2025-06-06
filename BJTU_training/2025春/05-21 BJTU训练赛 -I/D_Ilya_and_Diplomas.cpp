#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, seg, 3);
  vector<ll> ans(3);
  ans[0] = MIN(seg[0].second, n - seg[1].first - seg[2].first);
  ans[1] = MIN(seg[1].second, n - seg[2].first - ans[0]);
  ans[2] = n - ans[0] - ans[1];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"