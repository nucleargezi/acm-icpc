#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(PII, a, n);
  ll bs = QMIN(a).first;
  FOR(i, n) a[i].first -= bs;
  dynamic_seg<monoid_max<int>> rg(n << 5, 0, 3'000'000'01);
  dynamic_seg<monoid_add<int>> dp(n << 5, 0, 3'000'000'01);
  meion rt = rg.new_root();
  meion art = dp.new_root();
  meion I = argsort(a);
  for (int id : std::views::reverse(I)) {
    meion [x, h] = a[id];
    rg.set(rt, x, x + h);
    rg.set(rt, x, rg.prod(rt, x, x + h));
    dp.set(art, x, 1);
  }
  for (int id : I) {
    meion [x, h] = a[id];
    dp.set(art, x, dp.prod(art, x, rg.prod(rt, x, x + 1)));
  }
  vector<int> ans;
  FOR(i, n) {
    meion [x, h] = a[i];
    ans += dp.prod(art, x, x + 1);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"