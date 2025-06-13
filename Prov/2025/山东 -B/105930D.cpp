#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

#define tests
void Yorisou() {
  LL(n, q);
  vector<ll> ans(n << 1);
  ll al = 0;
  FOR(q) {
    LL(x, y);
    al += x / n;
    x %= n;
    ++ans[y];
    --ans[y + x];
  }
  ans = pre_sum<false>(ans);
  FOR(i, n) ans[i] += ans[i + n] + al;
  ans.resize(n);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"