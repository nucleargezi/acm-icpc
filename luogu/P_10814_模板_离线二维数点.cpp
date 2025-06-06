#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  Wavelet_Matrix seg(a);
  FOR(q) {
    LL(l, r, h);
    --l, ++h;
    UL(seg.count(l, r, 0, h));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"