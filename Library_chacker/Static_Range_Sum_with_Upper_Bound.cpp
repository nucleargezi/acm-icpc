#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/ds/wave_matrix.hpp"
#include "YRS/ds/fenw/fenw.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(ll, a, N);
  wave_matrix<ll, false, fenw<monoid_add<ll>>> seg(a, a);
  while (Q--) {
    INT(l, r, x);
    ++x;
    UL(seg.prefix_count_and_prod(l, r, x));
  }
}
#include "YRS/Z_H/main.hpp"