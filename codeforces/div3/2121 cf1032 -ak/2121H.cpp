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
    meion [s, min, max] = seg.prod(0, l);
    if (max == inf<ll>) std::tie(s, min, max) = T3<ll>{0, 0, 0};
    seg.chmax(l, r + 1, max + 1);
    std::tie(s, min, max) = seg.prod(l, r + 1);
    if (not ans.empty()) chmax(max, ans.back());
    ans.emplace_back(max);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"