#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

// #define tests
using splay = splay_monoid<monoid_add<ll>>;
using np = splay::np;
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  splay seg(1'000'000, a);
  np &rt = seg.rt;
  FOR(q) {
    LL(op, l, r);
    if (op == 0) {
      seg.reverse(rt, l, r);
    } else {
      UL(seg.prod(rt, l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"