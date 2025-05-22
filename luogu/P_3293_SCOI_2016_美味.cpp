#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  Wavelet_Matrix seg(a);
  FOR(q) {
    LL(b, x, l, r);
    --l;
    int ans = 0;
    FOR_R(i, 18) {
      if (b >> i & 1) {
        if (not seg.count(
                l, r, MAX(0ll, ans - x), MAX(0ll, ans - x + (1 << i)))) {
          ans |= 1 << i;
        }
      } else {
        if (seg.count(l, r, MAX(0ll, ans - x + (1 << i)),
                MAX(0ll, ans - x + (1 << i + 1)))) {
          ans |= 1 << i;
        }
      }
    }
    UL(ans ^ b);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"