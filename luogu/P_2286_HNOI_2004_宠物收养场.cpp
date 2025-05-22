#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using Splay = splay_sequence<int>;
using mint = modint<1000000>;
void Yorisou() {
  constexpr int N = 1'0'000'000;
  Splay seg(N);
  LL(q);
  mint ans;
  int a = 0, b = 0;
  meion f = [&](int x) -> void {
    PII ad = inf<PII>;
    if (seg.find(x)) {
      ad = {0, x};
    } else {
      meion lp = seg.pre(x);
      if (lp) {
        chmin(ad, PII(ABS(x - *lp), *lp));
      }
      meion rp = seg.nxt(x);
      if (rp) {
        chmin(ad, PII(ABS(x - *rp), *rp));
      }
    }
    ans += ad.first;
    seg.del(ad.second);
  };
  FOR(q) {
    LL(op, x);
    if (op == 0) {
      if (not b) seg.insert(x);
      else f(x);
      a += not b;
      b -= not not b;
    } else {
      if (not a) seg.insert(x);
      else f(x);
      b += not a;
      a -= not not a;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"