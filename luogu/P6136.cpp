#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/splay/splay_sequence.hpp"

void before() {}

// #define tests
using Splay = splay_sequence<int>;
void Yorisou() {
  constexpr int N = 1'0'000'000;
  Splay seg(N);
  LL(n, q);
  VEC(int, a, n);
  sort(a);
  seg.rt = seg.new_node(a);
  int last = 0, ans = 0;
  FOR(q) {
    LL(op, x);
    x ^= last;
    if (op == 1) {
      seg.insert(x);
    } else if (op == 2) {
      seg.del(x);
    } else if (op == 3) {
      last = seg.get_rank(x) + 1;
    } else if (op == 4) {
      last = *seg.kth(--x);
    } else if (op == 5) {
      last = *seg.pre(x);
    } else {
      last = *seg.nxt(x);
    }
    if (op > 2) ans ^= last;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"