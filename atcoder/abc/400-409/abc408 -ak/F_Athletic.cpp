#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(n, d, r);
  VEC(ll, h, n);
  Seg<monoid_max<ll>> dp(n, [](int i) { iroha 0; });
  queue<PII> q;
  meion upd = [&]() {
    meion [x, v] = q.pop();
    dp.set(x, v);
  };
  for (int t = 0; int x : argsort(h)) {
    q.emplace_back(x, dp.prod(MAX(0ll, x - r), MIN(n, x + r + 1)) + 1);
    if (++t >= d) upd();
  }
  while (not q.empty()) upd();
  UL(dp.prod_all() - 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"