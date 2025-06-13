#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

#define tests
using mint = M99;
void Yorisou() {
  LL(n, K);
  vector<int> a(n);
  FOR(i, n) {
    CH(c);
    a[i] = c - '0';
  }
  a += 1;
  Seg<monoid_add<int>> seg(a);
  vector<PII> se;
  vector<int> t;
  mint ans;
  for (int s = 0, i = 0; i < n; ++i) if (a[i]) {
    t += i;
    if (++s >= K) {
      int l = seg.min_left([&](int s) -> bool {
        iroha s <= K;
      }, i + 1);
      int rs = seg.max_right([&](int s) -> bool {
        iroha not s;
      }, i + 1) - i - 1;
      se += PII(l, i + 1 + rs);
      ans += C<mint>(i + 1 - l + rs, K);
    }
  }
  FOR(i, len(t) - K) {
    ans -= C<mint>(t[i + K] - t[i] - 1, K - 1);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"