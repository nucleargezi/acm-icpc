#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/beats_sum_minmax_chminmax.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(PII, LR, n);
  vector<ll> f;
  for (meion [l, r] : LR) f += l, f += r;
  unique(f);
  for (meion &[l, r] : LR) {
    l = lower_bound(f, l);
    r = lower_bound(f, r);
  }
  vector<ll> ans;
  beats_sum_minmax_chminmax<ll> seg(n + n, [](int i) { iroha 0ll; });
  for (meion [l, r] : LR) {
    seg.add(l, r + 1, 1);
    seg.chmax(l, r + 1, std::get<2>(seg.prod(0, l)) + 1);
    ans.emplace_back(std::get<2>(seg.prod(0, n << 1)));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"