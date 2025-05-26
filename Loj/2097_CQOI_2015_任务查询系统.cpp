#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"
#include "MeIoN_Lib/ds/monoid/add_pair.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  vector<vector<int>> go(n + 1);
  FOR(n) {
    LL(l, r, x);
    go[--l] += x;
    go[r] += -x;
  }
  constexpr int N = 1'000'0001;
  dynamic_seg<monoid_add_pair<ll>, 1> seg(n + 1 + q << 5, 0, N);
  vector<decltype(seg)::np> rt(n + 1);
  rt[0] = seg.new_root();
  FOR(i, n + 1) {
    rt[i] = i ? rt[i - 1] : rt[i];
    sort(go[i], greater());
    for (int x : go[i]) {
      rt[i] = seg.apply(rt[i], ABS(x), {x, x > 0 ? 1 : -1});
    }
  }
  ll ans = 1;
  FOR(q) {
    LL(x, a, b, c);
    --x;
    ll k = 1 + (a * ans + b) % c;
    meion [s, cnt] = seg.prod(rt[x], 0, N);
    if (k >= cnt) {
      UL(ans = s);
      continue;
    }
    int l = seg.min_left(rt[x], [&](pair<ll, ll> x) -> bool {
      meion [s, c] = x;
      iroha c <= cnt - k;
    }, N);
    std::tie(s, cnt) = seg.prod(rt[x], 0, l);
    meion [ls, lcnt] = seg.prod(rt[x], 0, l - 1);
    UL(ans = ls + (k - lcnt) * ((cnt - lcnt) ? (s - ls) / (cnt - lcnt) : 0));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"