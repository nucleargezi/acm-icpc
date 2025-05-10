#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, q);
  VEC(int, a, n);
  Wavelet_Matrix seg(a);
  for (int i = 0, l, r, k; i < q; ++i) {
    IN(l, r, k);
    UL(seg.kth(--l, r, --k));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"