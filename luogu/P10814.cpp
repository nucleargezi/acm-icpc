#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/ds/wave_matrix.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  wave_matrix<int, false> seg(a);
  FOR(q) {
    LL(l, r, h);
    --l, ++h;
    UL(seg.count(l, r, 0, h));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"