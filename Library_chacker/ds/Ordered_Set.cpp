#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"

void before() {}

// #define tests
using Splay = splay_sequence<int>;
void Yorisou() {
  Splay seg(1'000'000);
  
  LL(n, q);
  FOR(n) {
    LL(x);
    seg.insert(x);
  }

  FOR(q) {
    LL(op, x);
    if (op == 0) {
      if (not seg.find(x)) {
        seg.insert(x);
      }
    } else if (op == 1) {
      if (seg.find(x)) {
        seg.del(x);
      }
    } else if (op == 2) {
      meion ans = seg.kth(--x);
      UL(ans ? *ans : -1);
    } else if (op == 3) {
      UL(seg.get_rank(x + 1));
    } else if (op == 4) {
      meion ans = seg.pre(x + 1);
      UL(ans ? *ans : -1);
    } else {
      meion ans = seg.nxt(x - 1);
      UL(ans ? *ans : -1);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"