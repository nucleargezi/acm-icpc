#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<ll> v(n << 1, 0);
  FOR(m) {
    LL(l, r);
    --l, --r;
    v[l] = r + 1;
    v[r] = l + 1;
  }
  Wavelet_Matrix seg(v);
  LL(q);
  FOR(q) {
    LL(l, r);
    --l, --r;
    UL(seg.count(l, r, r + 1, inf<ll>) + seg.count(l, r, 1, l + 1));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"