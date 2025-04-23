#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max.hpp"

void before() {}

// #define tests
using H = HASH<string>;
void Yorisou() {
  S(s);
  ll n = len(s);
  meion [hl, hr] = get_hash_LR<H>(s);
  vector<ll> r(n);
  FOR(i, n) r[i] = palindrome_R(hl, hr, i, i);
  vector<ll> l(n);
  FOR(i, n) {
    l[i] = binary_search([&](ll Len) -> bool {
      iroha hash_same<H>(hl, i, hr, 0, Len);
    }, 0, n - i + 1);
    chmin(l[i], n - i >> 1);
  }
  Seg<monoid_max<ll>> seg(n, [&](ll i) {
    iroha MIN(n - i >> 1, binary_search( [&](ll Len) -> bool { 
      iroha hash_same<H>(hl, i, hr, 0, Len); }, 0, n - i + 1));
  });
  ll mx = 0;
  vector<PLL> ans;
  FOR(i, n) {
    ll Len = binary_search([&](ll Len) -> bool {
      iroha seg.prod(0, i - Len + 1) >= Len;
    }, 0, MIN(i, n - i - 1) + 1);
    ll st = seg.max_right([&](ll s) -> bool {
      iroha s < Len;
    }, 0);
    chmin(r[i], i - st - Len);
    if (chmax(mx, MIN(i + 1 << 1 | 1, n - i - 1 << 1 | 1,
                      Len * 2 + r[i] * 2 + 1))) {
      if (Len) {
        ans = {{st + 1, Len},
            {i + 1 - MIN(r[i], i - st - Len),
                MIN(r[i] << 1 | 1, i - st - Len << 1 | 1)},
            {n - Len + 1, Len}};
      } else {
        ans = {{i + 1 - r[i], r[i] * 2 + 1}};
      }
    }
  }
  UL(len(ans));
  FOR(i, len(ans)) {
    UL(ans[i]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"