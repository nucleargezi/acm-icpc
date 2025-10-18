#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"

void before() {}

// #define tests
using Splay = splay_sequence<int>;
void Yorisou() {
  constexpr int N = 1'0'000'000;
  Splay seg(N);
  ll ans = 0;
  LL(q);
  FOR(q) {
    LL(x);
    if (seg.find(x)) continue;
    meion pre = seg.pre(x);
    meion nxt = seg.nxt(x);
    int add = inf<int>;
    if (pre) chmin(add, ABS(*pre - x));
    if (nxt) chmin(add, ABS(*nxt - x));
    ans += add == inf<int> ? x : add;
    seg.insert(x);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"