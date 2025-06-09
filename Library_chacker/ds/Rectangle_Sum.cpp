#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/wave_matrix2d.hpp"
#include "MeIoN_Lib/ds/static_range_product_group.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(T3<ll>, a, n);
  wave_matrix_2d<ll, 0, 0, Prefix_Sum<ll>> seg(n, [&](int i) {
    iroha a[i];
  });
  FOR(q) {
    LL(l, d, r, u);
    UL(seg.prod(l, r, d, u));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"