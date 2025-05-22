#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"

void before() {}

// #define tests
using Splay = splay_sequence<int>;
void Yorisou() {
  constexpr int N = 1'0'000'000;
  Splay seg(N);
  LL(q);
  FOR(q) {
    LL(op);
    LL(x);
    if (op == 1) {
      seg.insert(x);
    } else if (op == 2) {
      seg.del(x);
    } else if (op == 3) {
      UL(seg.get_rank(x) + 1);
    } else if (op == 4) {
      UL(*seg.kth(--x));
    } else if (op == 5) {
      UL(*seg.pre(x));
    } else {
      UL(*seg.nxt(x));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"