#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/range_quis/range_inverse_count.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  range_inverse_count seg(a);
  seg.read_quis<0>(q);
  for (ll x : seg.count()) {
    UL(x);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"