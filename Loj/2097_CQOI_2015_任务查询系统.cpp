#include "YRS/all.hpp"
#include "YRS/ds/seg/dynamic_seg.hpp"
#include "YRS/ds/monoid/add_pair.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  vc<vc<int>> go(n + 1);
  FOR(n) {
    LL(l, r, x);
    go[l - 1].ep(x);
    go[r].ep(-x);
  }
  constexpr int N = 1'000'0001;
  dynamic_seg<monoid_add_pair<ll>, 1> seg(0, N);
  vc<decltype(seg)::np> rt(n + 1);
  rt[0] = nullptr;
  FOR(i, n + 1) {
    rt[i] = i ? rt[i - 1] : rt[i];
    sort(go[i], greater());
    for (int x : go[i]) {
      rt[i] = seg.multiply(rt[i], std::abs(x), {x, x > 0 ? 1 : -1});
    }
  }
  ll ans = 1;
  FOR(q) {
    LL(x, a, b, c);
    --x;
    ll k = 1 + (a * ans + b) % c;
    Z [s, cnt] = seg.prod(rt[x], 0, N);
    if (k >= cnt) {
      print(ans = s);
      continue;
    }
    int l = seg.min_left(rt[x], [&](pair<ll, ll> x) -> bool {
      Z [s, c] = x;
      return c <= cnt - k;
    }, N);
    tie(s, cnt) = seg.prod(rt[x], 0, l);
    Z [ls, lcnt] = seg.prod(rt[x], 0, l - 1);
    print(ans = ls + (k - lcnt) * ((cnt - lcnt) ? (s - ls) / (cnt - lcnt) : 0));
  }
}