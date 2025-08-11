#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/online_range_q/range_major_voting.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  major_voting seg(a, q);
  
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(i, x);
      seg.set(i, x);
    } else {
      LL(l, r);
      UL(seg.prod(l, r));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"