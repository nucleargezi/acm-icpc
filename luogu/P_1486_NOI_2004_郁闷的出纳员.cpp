#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"
#include "MeIoN_Lib/ds/splay/splay_acted_monoid.hpp"
#include "MeIoN_Lib/ds/a_monoid/min_add.hpp"

void before() {}

// #define tests
using Splay = splay_acted_monoid<a_monoid_min_add<int>>;
void Yorisou() {
  constexpr int N = 1'0'000'000;
  Splay seg(N);
  INT(q, min);
  int ans = 0;
  FOR(q) {
    CH(op);
    INT(K);
    if (op == 'I') {
      if (K > min - 1) seg.insert(K);
    } else if (op == 'A') {
      seg.apply_all(K);
    } else if (op == 'S') {
      seg.apply_all(-K);
    } else {
      meion p = seg.rt ? seg.kth(seg.rt->size - K) : std::nullopt;
      UL(p ? *p : -1);
    }
    while (seg.rt) {
      meion p = seg.kth(0);
      if (*p < min)
        seg.del(*p), ++ans;
      else
        break;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"