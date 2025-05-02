#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  Wavelet_Matrix seg(a);
  ll ans = 0;
  FOR(i, n) {
    ans += seg.count(0, i, a[i], inf<int>) == i;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"